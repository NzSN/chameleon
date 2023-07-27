
// Generated from ChameleonsParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ChameleonsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ChameleonsParser.
 */
class  ChameleonsParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(ChameleonsParser::ProgContext *ctx) = 0;
  virtual void exitProg(ChameleonsParser::ProgContext *ctx) = 0;

  virtual void enterRewriteRules(ChameleonsParser::RewriteRulesContext *ctx) = 0;
  virtual void exitRewriteRules(ChameleonsParser::RewriteRulesContext *ctx) = 0;

  virtual void enterRewriteRule(ChameleonsParser::RewriteRuleContext *ctx) = 0;
  virtual void exitRewriteRule(ChameleonsParser::RewriteRuleContext *ctx) = 0;

  virtual void enterSourcePattern(ChameleonsParser::SourcePatternContext *ctx) = 0;
  virtual void exitSourcePattern(ChameleonsParser::SourcePatternContext *ctx) = 0;

  virtual void enterTargetPattern(ChameleonsParser::TargetPatternContext *ctx) = 0;
  virtual void exitTargetPattern(ChameleonsParser::TargetPatternContext *ctx) = 0;


};
