#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <initializer_list>

#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <concepts>
#include <utility>

#include "antlr4-runtime.h"

using std::string;

namespace Rule {
namespace Interpreter {
namespace Language {


template<typename T>
concept Language = requires(T t, std::istream& is, std::string str) {
  { t.parseTreeFromStream(is) } -> std::same_as<antlr4::tree::ParseTree*>;
  { t.parseTreeFromString(str) } -> std::same_as<antlr4::tree::ParseTree*>;
};

template<Language T>
using MigrateInput = std::pair<const std::istream&, T>;


///////////////////////////////////////////////////////////////////////////////
//                                   Codes                                   //
///////////////////////////////////////////////////////////////////////////////
template<typename C>
concept CodeStrT  = requires(C c) {
  // Interface that gurantee that all escape in CodeString
  // are trim to it's original form. If there are no escaped
  // defined in your language then just return without any addition
  // processing.
  { c.withoutEscape() } -> std::convertible_to<string>;

  // Mapping to std::string which escape cahracter remain exists
  { c.toStr() } -> std::convertible_to<string>;
};

// A structure to contain Codes that
template<CodeStrT T>
class Code {
public:
  Code(T code): codeBytes_{code} {}
  string codeBytes() const
    { return codeBytes_.withoutEscape(); }
private:
  const T codeBytes_;
};

class CodeStr {
public:
  CodeStr(std::string codestr): codeString_{codestr} {}
  virtual string toStr() const;
  virtual string withoutEscape() const;
private:
  string codeString_;
};

using OriginCode = Code<CodeStr>;
using TargetCode = Code<CodeStr>;

///////////////////////////////////////////////////////////////////////////////
//                                MigrateRule                                //
///////////////////////////////////////////////////////////////////////////////
template<Language T>
struct MigrateRule {
  MigrateRule(std::string ident, OriginCode ocode, TargetCode tcode):
    identifier(ident), originCode(ocode), targetCode(tcode) {}

  void operator()(MigrateInput<T> input, std::ostream& os) const {

  }

  const std::string identifier;
  OriginCode originCode;
  TargetCode targetCode;
};

template<Language T>
struct MigrateRules {
  std::vector<MigrateRule<T>> rules;
  MigrateRules(std::initializer_list<MigrateRule<T>> rule_list):
    rules{rule_list} {}

  typename std::vector<MigrateRule<T>>::const_iterator
  begin() const { return std::begin(rules); }

  typename std::vector<MigrateRule<T>>::const_iterator
  end() const { return std::end(rules); }

  void operator()(MigrateInput<T> input, std::ostream& os) const {
    for (auto& rule: rules) {
      rule(input, os);
    }
  }
};

///////////////////////////////////////////////////////////////////////////////
//                                  Migrate                                  //
///////////////////////////////////////////////////////////////////////////////
template<Language T>
struct Migrate {
  Migrate(std::initializer_list<MigrateRule<T>> rule_list):
    migrateRules{rule_list} {}

  MigrateRules<T> migrateRules;

  // Evaluation of a 'Migrate' Entity is to perform actions to
  // migrating codes from 'istream' to 'ostream' with Rules within
  // the 'Migrate' Entity.
  void operator()(MigrateInput<T> input, std::ostream& os) const {
    migrateRules(input, os);
  }
};

} // Rule
} // Interpreter
} // Language

#endif /* LANGUAGE_H */
