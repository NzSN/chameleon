#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <typeinfo>
#include <plog/Log.h>
#include "generic_parsetree.h"
#include <iostream>
#include <vector>
#include <optional>

namespace Rules::Interpreter::Language {

struct GenericParseTreeTest: public ::testing::Test {
  // Generate arbitary parsetree contains
  // only N nodes (include the root node).
  std::optional<GenericParseTree<int>> genTreeWithN(const int n) {
    if (n == 0) return std::nullopt;

    GenericParseTree<int> root{1};

    std::function<void(GenericParseTree<int>*,int)>
      genSubTreeWithN = [&](GenericParseTree<int>* root, int nsubs) {
        while (nsubs > 0) {
          // Create directly child
          GenericParseTree<int>& child = root->addChild(1);
          nsubs -= 1;
          if (nsubs == 0) { return; }

          // Create a subtree with M nodes,
          // M is in range [0, remain]
          int m = *rc::gen::inRange(0, nsubs);
          genSubTreeWithN(&child, m);
          nsubs -= m;
        }
    };

    genSubTreeWithN(&root, n - 1);
    return root;
  }

  int traverseN(GenericParseTree<int>& tree) {
    const auto& counting =
      [&](GenericParseTree<int>& tree) -> bool {
      if (reached.size() == 0) {
        ++node_counter;
      }
      for (auto addr: reached) {
        if (addr != &tree) {
          ++node_counter;
          reached.push_back(&tree);
        }
      }
      return true;
    };
    tree.traverse(counting);

    return node_counter;
  }

  GenericParseTree<int>& getNodeRandomly(GenericParseTree<int>& tree) {
    int counter = *rc::gen::inRange(100, 1000);

    const auto& selectNode =
      [&](GenericParseTree<int>& tree) -> bool {
        --counter;
        if (counter == 0) {
          return true;
        }
        return false;
      };

    GenericParseTree<int>* node = NULL;
    while (!node) {
      node = tree.select(selectNode);
    }
    return *node;
  }

  int node_counter = 0;
  std::vector<void*> reached;
};


RC_GTEST_FIXTURE_PROP(GenericParseTreeTest, Traverse, ()) {
  const int N = *rc::gen::inRange(0, 100);
  std::optional<GenericParseTree<int>> root = genTreeWithN(N);

  if (root.has_value()) {
    traverseN(root.value());
    RC_ASSERT(node_counter == N);
  }
}

RC_GTEST_FIXTURE_PROP(GenericParseTreeTest, EqReflexivity, ()) {
  // Check basic case
  GenericParseTree<int> terminal{1};
  RC_ASSERT(terminal == terminal);

  // Assume ParseTree with N node satisfy
  // reflexivity.
  std::optional<GenericParseTree<int>> root =
    genTreeWithN(*rc::gen::inRange(1, 100));
  RC_ASSERT(root.value() == root.value());

  // Check N + 1 case
  // Select a place to add
  // a node randomly.
  GenericParseTree<int>& node = getNodeRandomly(root.value());
  node.addChild(1);
  RC_ASSERT(root.value() == root.value());
}

} // Rules::Interpreter::Language