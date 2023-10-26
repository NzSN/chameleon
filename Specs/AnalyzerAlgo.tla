------- MODULE AnalyzerAlgo ------------
CONSTANT NULL, Nodes

LOCAL INSTANCE Naturals
LOCAL INSTANCE TLC
LOCAL INSTANCE Tree WITH NULL <- NULL
LOCAL INSTANCE TreeSamples

AnalyzeImpls ==
  [Tree(Nodes) \X Nodes ->
   {[info |-> i, status |-> s]:
    i \in ParsedData,
    s \in ParseTreeNodeStatus} \union {NULL}]

ASSUME analyze \in AnalyzeImpls

LOCAL DoAnalyze(T) ==
  LET rootNode == GetRoot(T)
      Analyzing[tree \in Tree(DOMAIN T),
                node_ \in DOMAIN T] ==
        LET result == analyze[T, node_]

            AnalyzingChildren[tree_ \in Tree(DOMAIN T),
                              node__ \in DOMAIN T,
                              idx \in Nat] ==
              IF idx <= NumOfChild(tree_, node__)
              THEN LET current_result == Analyzing[tree_, GetChild(tree_, node__, idx)]
                       remains == AnalyzingChildren[tree_, node__, idx+1]
                   IN  IF remains /= NULL
                       THEN [current_result EXCEPT
                             !.info = MergeDatas[current_result.info, remains.info],
                             !.status = "Done"]
                       ELSE current_result
                   \* No more children to analyze
              ELSE NULL

        IN  IF IsAnalyzing[result.status]
            \* Some of children still unanalyzed.
            THEN
              IF NumOfChild(tree, node_) > 0
              THEN LET result_children == AnalyzingChildren[tree, node_, 1]
                   IN  IF result_children /= NULL
                       THEN IF IsAnalyzeFinished[result_children.status]
                            THEN [result EXCEPT
                                  !.info = MergeDatas[result.info, result_children.info],
                                  !.status = "Done"]
                            ELSE Assert(FALSE, "Failed to analyze Tree: Not all finished")
                       ELSE Assert(FALSE, "Failed to parse children")
              ELSE Assert(FALSE, "Failed to analyze node: No child node to parse")
            ELSE
              IF IsAnalyzeFinished[result.status]
              THEN result
              ELSE Assert(FALSE, "Failed to analyze node")
  IN LET Ret == Analyzing[T, rootNode]
     IN  Ret.info

\* Analyze the tree which root
\* node as parameter.
Analyze(T) == DoAnalyze(T)



===========================================