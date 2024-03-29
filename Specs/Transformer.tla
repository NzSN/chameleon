---- MODULE Transformer ----
CONSTANT Rule, RuleConfig, NULL, ParseTree
VARIABLES transformer

LOCAL INSTANCE Sequences
LOCAL INSTANCE Naturals
LOCAL INSTANCE Strategy
LOCAL INSTANCE Rule
LOCAL INSTANCE Tree
LOCAL INSTANCE TLC

\* RuleConfig -> Seq(Rule)
ParseConfig[config \in RuleConfig] ==
  <<RuleInst(Tree[0], Tree[1]),
    RuleInst(Tree[0], Tree[1])>>

IsAlreadyTransformed[t \in Trees,
                     config \in RuleConfig] ==
  LET rules == ParseConfig[config]
      isRightPatterns[t_ \in Trees, rs \in Seq(Rule)] ==
        IF rs = <<>>
        THEN FALSE
        ELSE
          LET r == Head(rs)
          IN  RightPattern(r) = t_ \/
              isRightPatterns[t_, Tail(rs)]
  IN isRightPatterns[t, rules]

IsAnyRuleMatch[t \in Trees, config \in RuleConfig] ==
  LET rules == ParseConfig[config]
      isLeftPatterns[t_ \in Trees, rs \in Seq(Rule)] ==
        IF rs = <<>>
        THEN FALSE
        ELSE
          LET r == Head(rs)
          IN  LeftPattern(r) = t_ \/
              isLeftPatterns[t_, Tail(rs)]
  IN isLeftPatterns[t, rules]


\* ParseTree -> ParseTree
Transform[ast \in ParseTree,
          rule \in Rule] ==
  LET S == BasicStrategies \* Break the Rule into Strategies
      ApplyStrategies[ss \in Seq(Strategies),
                      rule_ \in Rule,
                      ast_ \in ParseTree,
                      env_ \in Seq(ParseTree)] ==
        IF ss = <<>>
        THEN <<rule_, ast_>>
        ELSE
          LET s == Head(ss)
              r == s[<<rule_,ast_, env_>>]
          IN  ApplyStrategies[Tail(ss), r[1], r[2], r[3]]
  \* Do transformation by apply each of strategies
  \* to rule.
  IN ApplyStrategies[S, rule, ast, <<>>][2]

TransRules[ast \in ParseTree, rules \in Seq(Rule)] ==
  IF rules = <<>>
  THEN ast
  ELSE
    LET currentRule == Head(rules)
        ast_    == Transform[ast, currentRule]
    IN TransRules[ast_, Tail(rules)]

TypeInvariant ==
  transformer = [out |-> NULL, config |-> NULL]

Init ==
  /\ TypeInvariant

Transforming(ast, config) ==
  /\ ast \in ParseTree
  /\ transformer' = [transformer EXCEPT
                     !.out = TransRules[ast,ParseConfig[config]],
                     !.config = config]

TransDone(transed_ast, config) ==
  /\ transformer.out # NULL
  \* Assert that the AST has already
  \* been transformed into right side
  \* pattern of rule.
  /\ IsAlreadyTransformed[transed_ast, config] \/
     (~IsAlreadyTransformed[transed_ast, config] /\
      ~IsAnyRuleMatch[transed_ast, config])
  /\ UNCHANGED transformer

Next == \/ \E t \in ParseTree:
           \E r \in Rule: Transforming(t,r)
        \/ \E t \in ParseTree:
           \E r \in Rule: TransDone(t, r)

Spec == Init /\ [][Next]_transformer
============================
