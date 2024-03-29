#include <variant>
#include "langs.h"
#include "generic_parsetree_antlr4.h"

namespace Chameleon::Base {

using GptGeneric =
  std::variant<
  // Antlr4 Parsers
  ParseTree<Antlr4Node>
  >;

using GptSupportLang = SUPPORTED_LANGUAGE;

} // Base
