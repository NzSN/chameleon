
// Generated from ./ChameleonsParser.g4 by ANTLR 4.13.0


#include "ChameleonsParserListener.h"
#include "ChameleonsParserVisitor.h"

#include "ChameleonsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ChameleonsParserStaticData final {
  ChameleonsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ChameleonsParserStaticData(const ChameleonsParserStaticData&) = delete;
  ChameleonsParserStaticData(ChameleonsParserStaticData&&) = delete;
  ChameleonsParserStaticData& operator=(const ChameleonsParserStaticData&) = delete;
  ChameleonsParserStaticData& operator=(ChameleonsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag chameleonsparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ChameleonsParserStaticData *chameleonsparserParserStaticData = nullptr;

void chameleonsparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (chameleonsparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(chameleonsparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ChameleonsParserStaticData>(
    std::vector<std::string>{
      "prog", "targetSection", "ruleSection", "strategySection", "rewriteRules", 
      "rewriteRule", "sourcePattern", "targetPattern", "whereExprs", "condExprs", 
      "condExpr", "term", "assignExpr", "callExpr", "arguments"
    },
    std::vector<std::string>{
      "", "'TARGET:'", "'RULES:'", "'STRATEGIES'", "'where'", "", "':'", 
      "'{|'", "'=>'", "", "", "'|}'", "';'", "", "", "':='", "'('", "')'", 
      "','"
    },
    std::vector<std::string>{
      "", "TARGET_TAG", "RULE_TAG", "STRATEGY_TAG", "WHERE", "IDENTIFIER", 
      "COLON", "OPENBRACE", "TRANSFORM", "WS", "CODEBYTES", "CLOSEBRACE", 
      "WHERE_EXPR_SEPERATOR", "LOGICOP", "ORDEROP", "ASSIGN", "LBRACE", 
      "RBRACE", "COMMA", "STRING", "WHERE_IDENTIFIER", "WS_WHERE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,21,131,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,1,0,1,0,1,0,1,0,1,0,1,0,3,0,38,8,0,1,1,1,1,1,1,1,2,1,2,1,2,1,3,
  	1,3,1,4,1,4,1,4,1,4,3,4,52,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,76,8,5,1,6,1,6,
  	1,7,1,7,1,8,1,8,1,8,1,8,3,8,86,8,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,94,8,9,
  	1,10,1,10,1,10,1,10,1,10,3,10,101,8,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	5,10,109,8,10,10,10,12,10,112,9,10,1,11,1,11,1,12,1,12,1,12,1,12,1,13,
  	1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,3,14,129,8,14,1,14,0,1,20,15,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,0,0,126,0,37,1,0,0,0,2,39,1,0,
  	0,0,4,42,1,0,0,0,6,45,1,0,0,0,8,51,1,0,0,0,10,75,1,0,0,0,12,77,1,0,0,
  	0,14,79,1,0,0,0,16,85,1,0,0,0,18,93,1,0,0,0,20,100,1,0,0,0,22,113,1,0,
  	0,0,24,115,1,0,0,0,26,119,1,0,0,0,28,128,1,0,0,0,30,31,3,2,1,0,31,32,
  	3,4,2,0,32,38,1,0,0,0,33,34,3,2,1,0,34,35,3,4,2,0,35,36,3,6,3,0,36,38,
  	1,0,0,0,37,30,1,0,0,0,37,33,1,0,0,0,38,1,1,0,0,0,39,40,5,1,0,0,40,41,
  	5,5,0,0,41,3,1,0,0,0,42,43,5,2,0,0,43,44,3,8,4,0,44,5,1,0,0,0,45,46,5,
  	3,0,0,46,7,1,0,0,0,47,52,3,10,5,0,48,49,3,10,5,0,49,50,3,8,4,0,50,52,
  	1,0,0,0,51,47,1,0,0,0,51,48,1,0,0,0,52,9,1,0,0,0,53,54,5,5,0,0,54,55,
  	5,6,0,0,55,56,5,7,0,0,56,57,3,12,6,0,57,58,5,11,0,0,58,59,5,8,0,0,59,
  	60,5,7,0,0,60,61,3,14,7,0,61,62,5,11,0,0,62,76,1,0,0,0,63,64,5,5,0,0,
  	64,65,5,6,0,0,65,66,5,7,0,0,66,67,3,12,6,0,67,68,5,11,0,0,68,69,5,8,0,
  	0,69,70,5,7,0,0,70,71,3,14,7,0,71,72,5,11,0,0,72,73,5,4,0,0,73,74,3,16,
  	8,0,74,76,1,0,0,0,75,53,1,0,0,0,75,63,1,0,0,0,76,11,1,0,0,0,77,78,5,10,
  	0,0,78,13,1,0,0,0,79,80,5,10,0,0,80,15,1,0,0,0,81,86,3,18,9,0,82,83,3,
  	18,9,0,83,84,3,16,8,0,84,86,1,0,0,0,85,81,1,0,0,0,85,82,1,0,0,0,86,17,
  	1,0,0,0,87,88,3,20,10,0,88,89,5,12,0,0,89,94,1,0,0,0,90,91,3,20,10,0,
  	91,92,3,18,9,0,92,94,1,0,0,0,93,87,1,0,0,0,93,90,1,0,0,0,94,19,1,0,0,
  	0,95,96,6,10,-1,0,96,101,3,26,13,0,97,101,3,24,12,0,98,101,3,22,11,0,
  	99,101,5,19,0,0,100,95,1,0,0,0,100,97,1,0,0,0,100,98,1,0,0,0,100,99,1,
  	0,0,0,101,110,1,0,0,0,102,103,10,6,0,0,103,104,5,14,0,0,104,109,3,20,
  	10,7,105,106,10,5,0,0,106,107,5,13,0,0,107,109,3,20,10,6,108,102,1,0,
  	0,0,108,105,1,0,0,0,109,112,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,
  	21,1,0,0,0,112,110,1,0,0,0,113,114,5,20,0,0,114,23,1,0,0,0,115,116,5,
  	20,0,0,116,117,5,15,0,0,117,118,3,20,10,0,118,25,1,0,0,0,119,120,5,20,
  	0,0,120,121,5,16,0,0,121,122,3,28,14,0,122,123,5,17,0,0,123,27,1,0,0,
  	0,124,129,5,20,0,0,125,126,5,20,0,0,126,127,5,18,0,0,127,129,3,28,14,
  	0,128,124,1,0,0,0,128,125,1,0,0,0,129,29,1,0,0,0,9,37,51,75,85,93,100,
  	108,110,128
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  chameleonsparserParserStaticData = staticData.release();
}

}

ChameleonsParser::ChameleonsParser(TokenStream *input) : ChameleonsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ChameleonsParser::ChameleonsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ChameleonsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *chameleonsparserParserStaticData->atn, chameleonsparserParserStaticData->decisionToDFA, chameleonsparserParserStaticData->sharedContextCache, options);
}

ChameleonsParser::~ChameleonsParser() {
  delete _interpreter;
}

const atn::ATN& ChameleonsParser::getATN() const {
  return *chameleonsparserParserStaticData->atn;
}

std::string ChameleonsParser::getGrammarFileName() const {
  return "ChameleonsParser.g4";
}

const std::vector<std::string>& ChameleonsParser::getRuleNames() const {
  return chameleonsparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& ChameleonsParser::getVocabulary() const {
  return chameleonsparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ChameleonsParser::getSerializedATN() const {
  return chameleonsparserParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

ChameleonsParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ChameleonsParser::TargetSectionContext* ChameleonsParser::ProgContext::targetSection() {
  return getRuleContext<ChameleonsParser::TargetSectionContext>(0);
}

ChameleonsParser::RuleSectionContext* ChameleonsParser::ProgContext::ruleSection() {
  return getRuleContext<ChameleonsParser::RuleSectionContext>(0);
}

ChameleonsParser::StrategySectionContext* ChameleonsParser::ProgContext::strategySection() {
  return getRuleContext<ChameleonsParser::StrategySectionContext>(0);
}


size_t ChameleonsParser::ProgContext::getRuleIndex() const {
  return ChameleonsParser::RuleProg;
}

void ChameleonsParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void ChameleonsParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any ChameleonsParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::ProgContext* ChameleonsParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ChameleonsParser::RuleProg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(37);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(30);
      targetSection();
      setState(31);
      ruleSection();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(33);
      targetSection();
      setState(34);
      ruleSection();
      setState(35);
      strategySection();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetSectionContext ------------------------------------------------------------------

ChameleonsParser::TargetSectionContext::TargetSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::TargetSectionContext::TARGET_TAG() {
  return getToken(ChameleonsParser::TARGET_TAG, 0);
}

tree::TerminalNode* ChameleonsParser::TargetSectionContext::IDENTIFIER() {
  return getToken(ChameleonsParser::IDENTIFIER, 0);
}


size_t ChameleonsParser::TargetSectionContext::getRuleIndex() const {
  return ChameleonsParser::RuleTargetSection;
}

void ChameleonsParser::TargetSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTargetSection(this);
}

void ChameleonsParser::TargetSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTargetSection(this);
}


std::any ChameleonsParser::TargetSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitTargetSection(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::TargetSectionContext* ChameleonsParser::targetSection() {
  TargetSectionContext *_localctx = _tracker.createInstance<TargetSectionContext>(_ctx, getState());
  enterRule(_localctx, 2, ChameleonsParser::RuleTargetSection);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(39);
    match(ChameleonsParser::TARGET_TAG);
    setState(40);
    match(ChameleonsParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleSectionContext ------------------------------------------------------------------

ChameleonsParser::RuleSectionContext::RuleSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::RuleSectionContext::RULE_TAG() {
  return getToken(ChameleonsParser::RULE_TAG, 0);
}

ChameleonsParser::RewriteRulesContext* ChameleonsParser::RuleSectionContext::rewriteRules() {
  return getRuleContext<ChameleonsParser::RewriteRulesContext>(0);
}


size_t ChameleonsParser::RuleSectionContext::getRuleIndex() const {
  return ChameleonsParser::RuleRuleSection;
}

void ChameleonsParser::RuleSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleSection(this);
}

void ChameleonsParser::RuleSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleSection(this);
}


std::any ChameleonsParser::RuleSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitRuleSection(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::RuleSectionContext* ChameleonsParser::ruleSection() {
  RuleSectionContext *_localctx = _tracker.createInstance<RuleSectionContext>(_ctx, getState());
  enterRule(_localctx, 4, ChameleonsParser::RuleRuleSection);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    match(ChameleonsParser::RULE_TAG);
    setState(43);
    rewriteRules();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrategySectionContext ------------------------------------------------------------------

ChameleonsParser::StrategySectionContext::StrategySectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::StrategySectionContext::STRATEGY_TAG() {
  return getToken(ChameleonsParser::STRATEGY_TAG, 0);
}


size_t ChameleonsParser::StrategySectionContext::getRuleIndex() const {
  return ChameleonsParser::RuleStrategySection;
}

void ChameleonsParser::StrategySectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStrategySection(this);
}

void ChameleonsParser::StrategySectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStrategySection(this);
}


std::any ChameleonsParser::StrategySectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitStrategySection(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::StrategySectionContext* ChameleonsParser::strategySection() {
  StrategySectionContext *_localctx = _tracker.createInstance<StrategySectionContext>(_ctx, getState());
  enterRule(_localctx, 6, ChameleonsParser::RuleStrategySection);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    match(ChameleonsParser::STRATEGY_TAG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RewriteRulesContext ------------------------------------------------------------------

ChameleonsParser::RewriteRulesContext::RewriteRulesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ChameleonsParser::RewriteRuleContext* ChameleonsParser::RewriteRulesContext::rewriteRule() {
  return getRuleContext<ChameleonsParser::RewriteRuleContext>(0);
}

ChameleonsParser::RewriteRulesContext* ChameleonsParser::RewriteRulesContext::rewriteRules() {
  return getRuleContext<ChameleonsParser::RewriteRulesContext>(0);
}


size_t ChameleonsParser::RewriteRulesContext::getRuleIndex() const {
  return ChameleonsParser::RuleRewriteRules;
}

void ChameleonsParser::RewriteRulesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRewriteRules(this);
}

void ChameleonsParser::RewriteRulesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRewriteRules(this);
}


std::any ChameleonsParser::RewriteRulesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitRewriteRules(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::RewriteRulesContext* ChameleonsParser::rewriteRules() {
  RewriteRulesContext *_localctx = _tracker.createInstance<RewriteRulesContext>(_ctx, getState());
  enterRule(_localctx, 8, ChameleonsParser::RuleRewriteRules);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(47);
      rewriteRule();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(48);
      rewriteRule();
      setState(49);
      rewriteRules();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RewriteRuleContext ------------------------------------------------------------------

ChameleonsParser::RewriteRuleContext::RewriteRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::RewriteRuleContext::IDENTIFIER() {
  return getToken(ChameleonsParser::IDENTIFIER, 0);
}

tree::TerminalNode* ChameleonsParser::RewriteRuleContext::COLON() {
  return getToken(ChameleonsParser::COLON, 0);
}

std::vector<tree::TerminalNode *> ChameleonsParser::RewriteRuleContext::OPENBRACE() {
  return getTokens(ChameleonsParser::OPENBRACE);
}

tree::TerminalNode* ChameleonsParser::RewriteRuleContext::OPENBRACE(size_t i) {
  return getToken(ChameleonsParser::OPENBRACE, i);
}

ChameleonsParser::SourcePatternContext* ChameleonsParser::RewriteRuleContext::sourcePattern() {
  return getRuleContext<ChameleonsParser::SourcePatternContext>(0);
}

std::vector<tree::TerminalNode *> ChameleonsParser::RewriteRuleContext::CLOSEBRACE() {
  return getTokens(ChameleonsParser::CLOSEBRACE);
}

tree::TerminalNode* ChameleonsParser::RewriteRuleContext::CLOSEBRACE(size_t i) {
  return getToken(ChameleonsParser::CLOSEBRACE, i);
}

tree::TerminalNode* ChameleonsParser::RewriteRuleContext::TRANSFORM() {
  return getToken(ChameleonsParser::TRANSFORM, 0);
}

ChameleonsParser::TargetPatternContext* ChameleonsParser::RewriteRuleContext::targetPattern() {
  return getRuleContext<ChameleonsParser::TargetPatternContext>(0);
}

tree::TerminalNode* ChameleonsParser::RewriteRuleContext::WHERE() {
  return getToken(ChameleonsParser::WHERE, 0);
}

ChameleonsParser::WhereExprsContext* ChameleonsParser::RewriteRuleContext::whereExprs() {
  return getRuleContext<ChameleonsParser::WhereExprsContext>(0);
}


size_t ChameleonsParser::RewriteRuleContext::getRuleIndex() const {
  return ChameleonsParser::RuleRewriteRule;
}

void ChameleonsParser::RewriteRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRewriteRule(this);
}

void ChameleonsParser::RewriteRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRewriteRule(this);
}


std::any ChameleonsParser::RewriteRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitRewriteRule(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::RewriteRuleContext* ChameleonsParser::rewriteRule() {
  RewriteRuleContext *_localctx = _tracker.createInstance<RewriteRuleContext>(_ctx, getState());
  enterRule(_localctx, 10, ChameleonsParser::RuleRewriteRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(53);
      match(ChameleonsParser::IDENTIFIER);
      setState(54);
      match(ChameleonsParser::COLON);
      setState(55);
      match(ChameleonsParser::OPENBRACE);
      setState(56);
      sourcePattern();
      setState(57);
      match(ChameleonsParser::CLOSEBRACE);
      setState(58);
      match(ChameleonsParser::TRANSFORM);
      setState(59);
      match(ChameleonsParser::OPENBRACE);
      setState(60);
      targetPattern();
      setState(61);
      match(ChameleonsParser::CLOSEBRACE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(63);
      match(ChameleonsParser::IDENTIFIER);
      setState(64);
      match(ChameleonsParser::COLON);
      setState(65);
      match(ChameleonsParser::OPENBRACE);
      setState(66);
      sourcePattern();
      setState(67);
      match(ChameleonsParser::CLOSEBRACE);
      setState(68);
      match(ChameleonsParser::TRANSFORM);
      setState(69);
      match(ChameleonsParser::OPENBRACE);
      setState(70);
      targetPattern();
      setState(71);
      match(ChameleonsParser::CLOSEBRACE);
      setState(72);
      match(ChameleonsParser::WHERE);
      setState(73);
      whereExprs();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourcePatternContext ------------------------------------------------------------------

ChameleonsParser::SourcePatternContext::SourcePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::SourcePatternContext::CODEBYTES() {
  return getToken(ChameleonsParser::CODEBYTES, 0);
}


size_t ChameleonsParser::SourcePatternContext::getRuleIndex() const {
  return ChameleonsParser::RuleSourcePattern;
}

void ChameleonsParser::SourcePatternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSourcePattern(this);
}

void ChameleonsParser::SourcePatternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSourcePattern(this);
}


std::any ChameleonsParser::SourcePatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitSourcePattern(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::SourcePatternContext* ChameleonsParser::sourcePattern() {
  SourcePatternContext *_localctx = _tracker.createInstance<SourcePatternContext>(_ctx, getState());
  enterRule(_localctx, 12, ChameleonsParser::RuleSourcePattern);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(ChameleonsParser::CODEBYTES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetPatternContext ------------------------------------------------------------------

ChameleonsParser::TargetPatternContext::TargetPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::TargetPatternContext::CODEBYTES() {
  return getToken(ChameleonsParser::CODEBYTES, 0);
}


size_t ChameleonsParser::TargetPatternContext::getRuleIndex() const {
  return ChameleonsParser::RuleTargetPattern;
}

void ChameleonsParser::TargetPatternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTargetPattern(this);
}

void ChameleonsParser::TargetPatternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTargetPattern(this);
}


std::any ChameleonsParser::TargetPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitTargetPattern(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::TargetPatternContext* ChameleonsParser::targetPattern() {
  TargetPatternContext *_localctx = _tracker.createInstance<TargetPatternContext>(_ctx, getState());
  enterRule(_localctx, 14, ChameleonsParser::RuleTargetPattern);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(ChameleonsParser::CODEBYTES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereExprsContext ------------------------------------------------------------------

ChameleonsParser::WhereExprsContext::WhereExprsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ChameleonsParser::CondExprsContext* ChameleonsParser::WhereExprsContext::condExprs() {
  return getRuleContext<ChameleonsParser::CondExprsContext>(0);
}

ChameleonsParser::WhereExprsContext* ChameleonsParser::WhereExprsContext::whereExprs() {
  return getRuleContext<ChameleonsParser::WhereExprsContext>(0);
}


size_t ChameleonsParser::WhereExprsContext::getRuleIndex() const {
  return ChameleonsParser::RuleWhereExprs;
}

void ChameleonsParser::WhereExprsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhereExprs(this);
}

void ChameleonsParser::WhereExprsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhereExprs(this);
}


std::any ChameleonsParser::WhereExprsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitWhereExprs(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::WhereExprsContext* ChameleonsParser::whereExprs() {
  WhereExprsContext *_localctx = _tracker.createInstance<WhereExprsContext>(_ctx, getState());
  enterRule(_localctx, 16, ChameleonsParser::RuleWhereExprs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      condExprs();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82);
      condExprs();
      setState(83);
      whereExprs();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondExprsContext ------------------------------------------------------------------

ChameleonsParser::CondExprsContext::CondExprsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ChameleonsParser::CondExprContext* ChameleonsParser::CondExprsContext::condExpr() {
  return getRuleContext<ChameleonsParser::CondExprContext>(0);
}

tree::TerminalNode* ChameleonsParser::CondExprsContext::WHERE_EXPR_SEPERATOR() {
  return getToken(ChameleonsParser::WHERE_EXPR_SEPERATOR, 0);
}

ChameleonsParser::CondExprsContext* ChameleonsParser::CondExprsContext::condExprs() {
  return getRuleContext<ChameleonsParser::CondExprsContext>(0);
}


size_t ChameleonsParser::CondExprsContext::getRuleIndex() const {
  return ChameleonsParser::RuleCondExprs;
}

void ChameleonsParser::CondExprsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondExprs(this);
}

void ChameleonsParser::CondExprsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondExprs(this);
}


std::any ChameleonsParser::CondExprsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitCondExprs(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::CondExprsContext* ChameleonsParser::condExprs() {
  CondExprsContext *_localctx = _tracker.createInstance<CondExprsContext>(_ctx, getState());
  enterRule(_localctx, 18, ChameleonsParser::RuleCondExprs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(87);
      condExpr(0);
      setState(88);
      match(ChameleonsParser::WHERE_EXPR_SEPERATOR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(90);
      condExpr(0);
      setState(91);
      condExprs();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondExprContext ------------------------------------------------------------------

ChameleonsParser::CondExprContext::CondExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ChameleonsParser::CallExprContext* ChameleonsParser::CondExprContext::callExpr() {
  return getRuleContext<ChameleonsParser::CallExprContext>(0);
}

ChameleonsParser::AssignExprContext* ChameleonsParser::CondExprContext::assignExpr() {
  return getRuleContext<ChameleonsParser::AssignExprContext>(0);
}

ChameleonsParser::TermContext* ChameleonsParser::CondExprContext::term() {
  return getRuleContext<ChameleonsParser::TermContext>(0);
}

tree::TerminalNode* ChameleonsParser::CondExprContext::STRING() {
  return getToken(ChameleonsParser::STRING, 0);
}

std::vector<ChameleonsParser::CondExprContext *> ChameleonsParser::CondExprContext::condExpr() {
  return getRuleContexts<ChameleonsParser::CondExprContext>();
}

ChameleonsParser::CondExprContext* ChameleonsParser::CondExprContext::condExpr(size_t i) {
  return getRuleContext<ChameleonsParser::CondExprContext>(i);
}

tree::TerminalNode* ChameleonsParser::CondExprContext::ORDEROP() {
  return getToken(ChameleonsParser::ORDEROP, 0);
}

tree::TerminalNode* ChameleonsParser::CondExprContext::LOGICOP() {
  return getToken(ChameleonsParser::LOGICOP, 0);
}


size_t ChameleonsParser::CondExprContext::getRuleIndex() const {
  return ChameleonsParser::RuleCondExpr;
}

void ChameleonsParser::CondExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondExpr(this);
}

void ChameleonsParser::CondExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondExpr(this);
}


std::any ChameleonsParser::CondExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitCondExpr(this);
  else
    return visitor->visitChildren(this);
}


ChameleonsParser::CondExprContext* ChameleonsParser::condExpr() {
   return condExpr(0);
}

ChameleonsParser::CondExprContext* ChameleonsParser::condExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ChameleonsParser::CondExprContext *_localctx = _tracker.createInstance<CondExprContext>(_ctx, parentState);
  ChameleonsParser::CondExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, ChameleonsParser::RuleCondExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(100);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(96);
      callExpr();
      break;
    }

    case 2: {
      setState(97);
      assignExpr();
      break;
    }

    case 3: {
      setState(98);
      term();
      break;
    }

    case 4: {
      setState(99);
      match(ChameleonsParser::STRING);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(110);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(108);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<CondExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleCondExpr);
          setState(102);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(103);
          match(ChameleonsParser::ORDEROP);
          setState(104);
          condExpr(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<CondExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleCondExpr);
          setState(105);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(106);
          match(ChameleonsParser::LOGICOP);
          setState(107);
          condExpr(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(112);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

ChameleonsParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::TermContext::WHERE_IDENTIFIER() {
  return getToken(ChameleonsParser::WHERE_IDENTIFIER, 0);
}


size_t ChameleonsParser::TermContext::getRuleIndex() const {
  return ChameleonsParser::RuleTerm;
}

void ChameleonsParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void ChameleonsParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


std::any ChameleonsParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::TermContext* ChameleonsParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 22, ChameleonsParser::RuleTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(ChameleonsParser::WHERE_IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignExprContext ------------------------------------------------------------------

ChameleonsParser::AssignExprContext::AssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::AssignExprContext::WHERE_IDENTIFIER() {
  return getToken(ChameleonsParser::WHERE_IDENTIFIER, 0);
}

tree::TerminalNode* ChameleonsParser::AssignExprContext::ASSIGN() {
  return getToken(ChameleonsParser::ASSIGN, 0);
}

ChameleonsParser::CondExprContext* ChameleonsParser::AssignExprContext::condExpr() {
  return getRuleContext<ChameleonsParser::CondExprContext>(0);
}


size_t ChameleonsParser::AssignExprContext::getRuleIndex() const {
  return ChameleonsParser::RuleAssignExpr;
}

void ChameleonsParser::AssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignExpr(this);
}

void ChameleonsParser::AssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignExpr(this);
}


std::any ChameleonsParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::AssignExprContext* ChameleonsParser::assignExpr() {
  AssignExprContext *_localctx = _tracker.createInstance<AssignExprContext>(_ctx, getState());
  enterRule(_localctx, 24, ChameleonsParser::RuleAssignExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(ChameleonsParser::WHERE_IDENTIFIER);
    setState(116);
    match(ChameleonsParser::ASSIGN);
    setState(117);
    condExpr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallExprContext ------------------------------------------------------------------

ChameleonsParser::CallExprContext::CallExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::CallExprContext::WHERE_IDENTIFIER() {
  return getToken(ChameleonsParser::WHERE_IDENTIFIER, 0);
}

tree::TerminalNode* ChameleonsParser::CallExprContext::LBRACE() {
  return getToken(ChameleonsParser::LBRACE, 0);
}

ChameleonsParser::ArgumentsContext* ChameleonsParser::CallExprContext::arguments() {
  return getRuleContext<ChameleonsParser::ArgumentsContext>(0);
}

tree::TerminalNode* ChameleonsParser::CallExprContext::RBRACE() {
  return getToken(ChameleonsParser::RBRACE, 0);
}


size_t ChameleonsParser::CallExprContext::getRuleIndex() const {
  return ChameleonsParser::RuleCallExpr;
}

void ChameleonsParser::CallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExpr(this);
}

void ChameleonsParser::CallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExpr(this);
}


std::any ChameleonsParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::CallExprContext* ChameleonsParser::callExpr() {
  CallExprContext *_localctx = _tracker.createInstance<CallExprContext>(_ctx, getState());
  enterRule(_localctx, 26, ChameleonsParser::RuleCallExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(ChameleonsParser::WHERE_IDENTIFIER);
    setState(120);
    match(ChameleonsParser::LBRACE);
    setState(121);
    arguments();
    setState(122);
    match(ChameleonsParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

ChameleonsParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ChameleonsParser::ArgumentsContext::WHERE_IDENTIFIER() {
  return getToken(ChameleonsParser::WHERE_IDENTIFIER, 0);
}

tree::TerminalNode* ChameleonsParser::ArgumentsContext::COMMA() {
  return getToken(ChameleonsParser::COMMA, 0);
}

ChameleonsParser::ArgumentsContext* ChameleonsParser::ArgumentsContext::arguments() {
  return getRuleContext<ChameleonsParser::ArgumentsContext>(0);
}


size_t ChameleonsParser::ArgumentsContext::getRuleIndex() const {
  return ChameleonsParser::RuleArguments;
}

void ChameleonsParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void ChameleonsParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ChameleonsParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any ChameleonsParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ChameleonsParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

ChameleonsParser::ArgumentsContext* ChameleonsParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 28, ChameleonsParser::RuleArguments);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(124);
      match(ChameleonsParser::WHERE_IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(125);
      match(ChameleonsParser::WHERE_IDENTIFIER);
      setState(126);
      match(ChameleonsParser::COMMA);
      setState(127);
      arguments();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ChameleonsParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return condExprSempred(antlrcpp::downCast<CondExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ChameleonsParser::condExprSempred(CondExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void ChameleonsParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  chameleonsparserParserInitialize();
#else
  ::antlr4::internal::call_once(chameleonsparserParserOnceFlag, chameleonsparserParserInitialize);
#endif
}
