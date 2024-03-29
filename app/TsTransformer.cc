#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "parsers/ts/TypeScriptLexer.h"
#include "parsers/ts/TypeScriptParser.h"
#include "parsers/ts/TypeScriptParserBaseListener.h"

class MyListener: public TypeScriptParserBaseListener {
public:
  void enterImportStatement(TypeScriptParser::ImportStatementContext* ctx) {
    std::string fromModule =
      ctx->fromBlock()->StringLiteral()->getSymbol()->getText();

    auto names = ctx->fromBlock()->multipleImportStatement()->identifierName();
    std::vector<std::string> importSyms(names.size());

    std::transform(names.cbegin(), names.cend(), importSyms.begin(),
                   [](TypeScriptParser::IdentifierNameContext* ictx) {
                     return ictx->Identifier()->getSymbol()->getText();
                   });
    std::cout << "Import symbols: ";
    for (auto is: importSyms) {
      std::cout << is << " ";
    }
    std::cout << "from " << fromModule << std::endl;
  }
};


int main(int argc, char *argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);

  antlr4::ANTLRInputStream input(stream);
  TypeScriptLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  TypeScriptParser parser(&tokens);


  antlr4::tree::ParseTree *tree = parser.program();

  // Print AST
  std::cout << "AST: " << std::endl << std::endl;
  std::cout << tree->toStringTree(&parser) << std::endl;
  std::cout << std::endl << std::endl <<
    "=============================================" <<
    std::endl;

  MyListener listener;
  antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

  return 0;
}
