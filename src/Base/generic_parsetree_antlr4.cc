#include <algorithm>
#include <exception>
#include <typeinfo>
#include <stdexcept>
#include <utility>

#include "langs.h"
#include "tree/ParseTreeType.h"
#include "generic_parsetree_antlr4.h"
#include "Misc/testLanguage/TestLangParser.h"

namespace Chameleon::Base {

struct FAILED_TO_CLONE_ANTLR_NODE: public std::exception {
  ~FAILED_TO_CLONE_ANTLR_NODE() {}
  const char* what() {
    return "Failed to clone Antlr4Node...";
  }
};

#define LANGS(V)                                \
  /* FIELDS : Namespace | LANG_ENUM */          \
  V(TestLang, TESTLANG)                         \
  V(WGSL, WGSL)

#define ANTLR_COPY_LANG_SPECIFIC(NAMESPACE, LANG_ENUM)         \
  case ParseTree<Antlr4Node>::LANG_ENUM: {                     \
    antlr4::tree::ParseTree* copy =                            \
      NAMESPACE::clone(const_cast<Antlr4Node*>(this)->tree()); \
    return std::make_unique<Antlr4Node>(                            \
      ParseTree<Antlr4Node>::LANG_ENUM,                        \
      copy);                                                   \
  }

#define ANTLR_COPY_LANG(LANG)                               \
  switch (LANG) {                                           \
    LANGS(ANTLR_COPY_LANG_SPECIFIC);                        \
  default:                                                  \
    throw FAILED_TO_CLONE_ANTLR_NODE{};                     \
  }

// Deep copy
Antlr4Node::Node Antlr4Node::clone() const {
  ANTLR_COPY_LANG(lang_);
}

#undef ANTLR_COPY_LANG
#undef ANTLR_COPY_LANG_SPECIFIC
#undef LANGS

Antlr4Node::Antlr4Node(int lang, antlr4::tree::ParseTree* tree):
  lang_{lang}, tree_{tree} {

  if (!tree) {
    throw std::runtime_error(
      "No antlr4 parsetree found (nullpointer)");
  }

  // Construct subtrees
  for (auto c: tree->children) {
    children_.push_back(
      std::make_unique<Antlr4Node>(lang, c));
  }

  for (auto& c: children_) {
    c->parent = this;
  }
}

// Shallow copy
Antlr4Node::Antlr4Node(const Antlr4Node& other):
  lang_{other.lang_}, tree_{other.tree_} {

  for (auto c: other.tree_->children) {
    children_.push_back(
      std::make_unique<Antlr4Node>(lang_, c));
  }

  for (auto& c: children_) {
    c->parent = this;
  }
}

// Shallow copy
Antlr4Node& Antlr4Node::operator=(const Antlr4Node& other) {
  lang_ = other.lang_;
  tree_ = other.tree_;

  if (children_.size() > 0) {
    children_.clear();
  }

  for (auto c: other.tree_->children) {
    children_.push_back(
      std::make_unique<Antlr4Node>(lang_, c));
  }

  return *this;
}

bool Antlr4Node::operator==(const Antlr4Node& node) const {
  if (this->tree_->getTreeType() !=
      node.tree_->getTreeType()) {

    return false;
  }

  if (this->tree_->getTreeType() ==
      antlr4::tree::ParseTreeType::RULE) {

    const std::type_info& leftTypeInfo = typeid(*this->tree_);
    const std::type_info& rightTypeInfo = typeid(*node.tree_);

    bool isEqual = leftTypeInfo == rightTypeInfo;

    #if ENABLE_GC
    if (!isEqual) {
      auto* lhs = dynamic_cast<GC::ContextInfo*>(this->tree_);
      auto* rhs = dynamic_cast<GC::ContextInfo*>(node.tree_);

      if (lhs && rhs) {
        return isEqual;
      } else if (lhs) {
        return lhs->typeName == rightTypeInfo.name();
      } else if (rhs) {
        return rhs->typeName == leftTypeInfo.name();
      }
    }
    #endif

    return isEqual;
  } else if (this->tree_->getTreeType() ==
             antlr4::tree::ParseTreeType::TERMINAL) {
    return this->tree_->getText() == node.tree_->getText();
  }

  return false;
}

// BUG: Inconsistent between layer after setNode is called
//      due to Antlr4Node not update it self after underlying
//      tree structure is changed.
bool Antlr4Node::setNode(const Antlr4Node& other) {
  if (tree_ == nullptr || other.tree_ == nullptr) {
    return false;
  }

  if (!tree_->parent) {
    return false;
  }

  antlr4::tree::ParseTree* tree = tree_;
  std::vector<antlr4::tree::ParseTree*>&
    siblings = tree_->parent->children;

  std::vector<antlr4::tree::ParseTree*> siblings_new(siblings.size());

  std::transform(siblings.cbegin(), siblings.cend(),
                 siblings.begin(),
                 [tree, &other](antlr4::tree::ParseTree* t) -> antlr4::tree::ParseTree* {
                   if (tree == t) {
                     return other.tree_;
                   }

                   return t;
                 });

  other.tree_->parent = tree_->parent;
  tree_ = other.tree_;

  // Update current layer to keep
  // consistent between layers.
  children_.clear();

  for (auto c: tree_->children) {
    children_.push_back(
      std::make_unique<Antlr4Node>(lang_, c));
  }
  for (auto& c: children_) {
    c->parent = this;
  }

  return true;
}

void Antlr4Node::appendChild(Node& node) {
  this->tree()->children.push_back(node->tree());
  children_.push_back(std::move(node));
}

void Antlr4Node::appendChild(Node&& node) {
  this->tree()->children.push_back(node->tree());
  children_.push_back(std::move(node));
}

namespace {

Antlr4Node* lowerAsPossible_TESTLANG(Antlr4Node* node) {
  if (typeid(*node->tree()) == typeid(TestLangParser::ProgContext)) {
    return node->getChildren()[0].get();
  } else {
    return node;
  }
}

Antlr4Node* lowerAsPossible_WGSL(Antlr4Node* node) {
  antlr4::tree::ParseTree* tree{node->tree()};

  if (typeid(*tree) ==
      typeid(WGSLParser::Translation_unitContext)) {
    using Ctx = WGSLParser::Translation_unitContext;
    Ctx* ctx = dynamic_cast<Ctx*>(tree);
    if (ctx->global_decl().size() != 0 &&
        ctx->global_directive().size() != 0) {
      // Already the lowest height without lost of
      // informations.
      return node;
    } else if (ctx->global_decl().size() != 0) {
      if (ctx->global_decl().size() > 1) {
        return node;
      } else {
        return node->getChildren()[0].get();
      }
    } else if (ctx->global_directive().size() != 0) {
      if (ctx->global_directive().size() > 1) {
        return node;
      } else {
        return node->getChildren()[0].get();
      }
    } else if (ctx->statement() != nullptr) {
      return node->getChildren()[0].get();
    } else if (ctx->expression() != nullptr) {
      return node->getChildren()[0].get();
    } else {
      std::unreachable();
    }
  }

  return node;
}

}

// Lower the root node to the lowest node that
// without lost informations.
Antlr4Node* Antlr4Node::lowerAsPossible() {
  switch (lang_) {
    case Base::SUPPORTED_LANGUAGE::TESTLANG:
      return lowerAsPossible_TESTLANG(this);
    case Base::SUPPORTED_LANGUAGE::WGSL:
      return lowerAsPossible_WGSL(this);
  default:
    std::unreachable();
  }
}

} // Base
