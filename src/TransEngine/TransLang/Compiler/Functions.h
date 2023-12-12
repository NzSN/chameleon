#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "utility.h"

#include "TransEngine/Rewrite/Expr/Expr.h"
#include "TransEngine/Rewrite/Environment.h"

/////////////////////////////////////////////////////////////////////////////
//                            TestLang Functions                           //
/////////////////////////////////////////////////////////////////////////////

#define TESTLANG_FUNCTIONS(V) \
  V(Plus)

// FIXME: Debug purposes
inline std::unique_ptr<Base::Antlr4Node> A;
inline std::unique_ptr<Base::GenericParseTree<Base::Antlr4Node>> B;

// Plus :: Term -> Term
struct Plus: public TransEngine::Expression::Function {
  Plus() {}

  std::unique_ptr<TransEngine::Expression::Value> operator()(
    TransEngine::Expression::Arguments* args) {

    if (args->args.size() != 1) {
      return nullptr;
    }

    // Try to convert the text presentation to integer,
    // no effects if failed to convert.
    if (!TransEngine::Expression::Value::isTerm(*args->args[0])) {
      return nullptr;
    }

    TransEngine::Expression::Term* term = dynamic_cast<TransEngine::Expression::Term*>(
      args->args[0].get());

    Base::GenericParseTree<Base::Antlr4Node>* gpt =
      &term->term->tree.get();

    int number{};
    std::string numberMaybe = gpt->getText();

    try {
      number = std::stoi(numberMaybe);
      ++number;
    } catch (const std::invalid_argument& e) {
      return nullptr;
    } catch (const std::out_of_range& e) {
      return nullptr;
    }

    // After that reconstruct a Term from the new number
    //
    // FIXME: Need a backing store to manage those resource allocated
    //        during evaluation of WhereClause otherwise segfault.
    std::unique_ptr<Base::Antlr4Node> metaCopy = gpt->getMeta().clone();
    std::unique_ptr<Base::GenericParseTree<Base::Antlr4Node>>
      gptCopy =
      Base::GenericParseTree<Base::Antlr4Node>
      ::mapping<Base::Antlr4Node, Utility::DYNAMIC>(*metaCopy);

    // Replace the original node by the copy node
    //
    // FIXME: If parser does not to manage the resource of
    //        the original node once it has been replaced
    //        and those resource should be reclaim here.
    // gpt->setNode(*gptCopy);

    // The type of underlying tree node should be antlr4::tree::TerminalNodeImpl,
    // which is a WritableToken. Hence, able to write the number into it.
    if (typeid(*const_cast<Base::Antlr4Node&>(gptCopy->getMeta()).tree())
        != typeid(antlr4::tree::TerminalNodeImpl)) {
      return nullptr;
    }

    antlr4::tree::TerminalNodeImpl* node =
      dynamic_cast<antlr4::tree::TerminalNodeImpl*>(
        const_cast<Base::Antlr4Node&>(
          gptCopy->getMeta()).tree());

    antlr4::CommonToken* token =
      dynamic_cast<antlr4::CommonToken*>(node->getSymbol());
    if (!token) {
      // Underlying type is not an antlr4::CommonToken
      return nullptr;
    }

    token->setText(std::to_string(number));

    // Create Term from gptCopy.
    TransEngine::Rewrite::Term<Base::Antlr4Node> rTerm{*gptCopy};

    // FIXME: Debug purposes
    A = std::move(metaCopy);
    B = std::move(gptCopy);

    return std::make_unique<TransEngine::Expression::Term>(rTerm);
  }
};

#endif /* FUNCTIONS_H */