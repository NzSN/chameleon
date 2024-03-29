
// Generated from ./ChameleonsParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ChameleonsParserVisitor.h"


/**
 * This class provides an empty implementation of ChameleonsParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ChameleonsParserBaseVisitor : public ChameleonsParserVisitor {
public:

  virtual std::any visitProg(ChameleonsParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTargetSection(ChameleonsParser::TargetSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRuleSection(ChameleonsParser::RuleSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStrategySection(ChameleonsParser::StrategySectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRewriteRules(ChameleonsParser::RewriteRulesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRewriteRule(ChameleonsParser::RewriteRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSourcePattern(ChameleonsParser::SourcePatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTargetPattern(ChameleonsParser::TargetPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhereExprs(ChameleonsParser::WhereExprsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondExprs(ChameleonsParser::CondExprsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondExpr(ChameleonsParser::CondExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(ChameleonsParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(ChameleonsParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallExpr(ChameleonsParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(ChameleonsParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }


};

