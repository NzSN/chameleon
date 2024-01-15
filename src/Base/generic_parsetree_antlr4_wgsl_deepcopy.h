#ifndef GENERIC_PARSETREE_WGSL_DEEPCOPY_H_
#define GENERIC_PARSETREE_WGSL_DEEPCOPY_H_

#include "generic_parsetree_antlr4_deepcopy.h"
#include "parsers/wgsl/WGSLBaseListener.h"

namespace WGSL {

#define WGSL_CONTEXTS(V)                                                       \
  V(WGSLParser, Translation_unit, Template_args_start)                         \
  V(WGSLParser, Translation_unit, Template_args_end)                           \
  V(WGSLParser, Translation_unit, Additive_operator)                           \
  V(WGSLParser, Translation_unit, Multiplicative_operator)                     \
  V(WGSLParser, Translation_unit, Argument_expression_list)                    \
  V(WGSLParser, Translation_unit, Assignment_statement)                        \
  V(WGSLParser, Translation_unit, Shift_expression_post_unary_expression)      \
  V(WGSLParser, Translation_unit, Attribute)                                   \
  V(WGSLParser, Translation_unit, Bitwise_expression_post_unary_expression)    \
  V(WGSLParser, Translation_unit, Case_selector)                               \
  V(WGSLParser, Translation_unit, Component_or_swizzle_specifier)              \
  V(WGSLParser, Translation_unit, Compound_statement)                          \
  V(WGSLParser, Translation_unit, Core_lhs_expression)                         \
  V(WGSLParser, Translation_unit, Diagnostic_control)                          \
  V(WGSLParser, Translation_unit, Diagnostic_rule_name)                        \
  V(WGSLParser, Translation_unit, Expression)                                  \
  V(WGSLParser, Translation_unit, Float_literal)                               \
  V(WGSLParser, Translation_unit, For_init)                                    \
  V(WGSLParser, Translation_unit, For_update)                                  \
  V(WGSLParser, Translation_unit, Global_decl)                                 \
  V(WGSLParser, Translation_unit, Global_directive)                            \
  V(WGSLParser, Translation_unit, Global_value_decl)                           \
  V(WGSLParser, Translation_unit, Ident)                                       \
  V(WGSLParser, Translation_unit, Int_literal)                                 \
  V(WGSLParser, Translation_unit, Lhs_expression)                              \
  V(WGSLParser, Translation_unit, Literal)                                     \
  V(WGSLParser, Translation_unit, Member_ident)                                \
  V(WGSLParser, Translation_unit, Optionally_typed_ident)                      \
  V(WGSLParser, Translation_unit, Param)                                       \
  V(WGSLParser, Translation_unit, Primary_expression)                          \
  V(WGSLParser, Translation_unit, Greater_than)                                \
  V(WGSLParser, Translation_unit, Less_than)                                   \
  V(WGSLParser, Translation_unit, Relational_expression_post_unary_expression) \
  V(WGSLParser, Translation_unit, Statement)                                   \
  V(WGSLParser, Translation_unit, Switch_clause)                               \
  V(WGSLParser, Translation_unit, Template_arg_expression)                     \
  V(WGSLParser, Translation_unit, Template_elaborated_ident_post_ident)        \
  V(WGSLParser, Translation_unit, Translation_unit)                            \
  V(WGSLParser, Translation_unit, Type_specifier)                              \
  V(WGSLParser, Translation_unit, Unary_expression)                            \
  V(WGSLParser, Translation_unit, Variable_decl)                               \
  V(WGSLParser, Translation_unit, Variable_or_value_statement)                 \
  V(WGSLParser, Translation_unit, Variable_updating_statement)


DEEPCOPY_IMPL(
  WGSLBaseListener,
  WGSL_CONTEXTS);

} // WGSL


#endif // GENERIC_PARSETREE_WGSL_DEEPCOPY_H_