
#ifndef GENERIC_PARSETREE_CONCRETE_H
#define GENERIC_PARSETREE_CONCRETE_H

#include <variant>
#include "generic_parsetree_antlr4.h"

namespace Base {

using GenericParseTreeT_DYNAMIC = std::variant<
  std::unique_ptr<GenericParseTree<Antlr4Node>>
  >;

} // Base

#endif /* GENERIC_PARSETREE_CONCRETE_H */