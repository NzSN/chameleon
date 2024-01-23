#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <tuple>
#include <optional>
#include <concepts>
#include <ranges>
#include <concepts>
#include <functional>
#include <type_traits>

#include "Base/langs.h"
#include "antlr4-runtime.h"

#include "Base/config.h"

namespace Utility {

enum ALLOC_STORAGE_DURATION {
  AUTOMATIC,
  DYNAMIC,
};

template<ALLOC_STORAGE_DURATION duration>
concept isAutoStorage = duration == ALLOC_STORAGE_DURATION::AUTOMATIC;

template<ALLOC_STORAGE_DURATION duration>
concept isDynamicStorage = duration == ALLOC_STORAGE_DURATION::DYNAMIC;


template<typename T, typename E>
concept RangeTuple = std::ranges::range<T> &&
  requires(T t, std::tuple<E, E> pair) {
    t.push_back(pair);
};

template<typename T, typename E>
concept Range = std::ranges::range<T>;

template<typename E, RangeTuple<E> RT, Range<E> T>
RT zip(T l, T r) {
  if (l.size() != r.size()) {
    return RT{};
  }

  RT zipped{};
  auto iter_l = std::begin(l);
  auto iter_r = std::begin(r);

  while (iter_l != std::end(l)) {
    zipped.push_back({*iter_l, *iter_r});

    ++iter_l;
    ++iter_r;
  }

    return zipped;
}


template<std::derived_from<antlr4::Lexer> Lexer,
         std::derived_from<antlr4::Parser> Parser,
         typename Entry>
struct Antlr4ParseEnv {
  Antlr4ParseEnv(std::string sentences, Entry entry):
    inputSStream{sentences},
    inputStream{inputSStream},
    input{inputSStream},
    tokens{&lexer},
    lexer{&input},
    parser{&tokens} {

    tree = (parser.*(entry))();
  }

  Antlr4ParseEnv(std::istream& istream, Entry entry):
    inputStream(istream),
    input{inputStream},
    tokens{&lexer},
    lexer{&input},
    parser{&tokens} {

    tree = (parser.*(entry))();
  }

  /* Caution: Order is important here, don't
   *          change the order of those declarations
   *          unless you know what you are doing. */
  std::istringstream inputSStream;
  std::istream& inputStream;
  antlr4::ANTLRInputStream input;
  antlr4::CommonTokenStream tokens;
  Lexer lexer;
  Parser parser;
  // This object is managed by Parser
  // so it's already owned.
  antlr4::tree::ParseTree* tree;
};

template<typename T>
const auto& zip_vector =
  zip<T, std::vector<std::tuple<T, T>>, const std::vector<T>&>;

template<std::derived_from<antlr4::Lexer> Lexer,
         std::derived_from<antlr4::Parser> Parser,
         typename Entry>
using Antlr4ParseEnvUniquePtr = std::unique_ptr<Antlr4ParseEnv<Lexer, Parser, Entry>>;

template<std::derived_from<antlr4::Lexer> Lexer,
         std::derived_from<antlr4::Parser> Parser,
         typename Entry>
Antlr4ParseEnvUniquePtr<Lexer, Parser, Entry>
Antlr4_GenParseTree(std::string sentences, Entry entry) {
  return std::make_unique<
    Antlr4ParseEnv<Lexer, Parser, Entry>>(sentences, entry);
}

template<std::derived_from<antlr4::Lexer> Lexer,
         std::derived_from<antlr4::Parser> Parser,
         typename Entry>
Antlr4ParseEnvUniquePtr<Lexer, Parser, Entry>
Antlr4_GenParseTree(std::istream& stream, Entry entry) {
  return std::make_unique<
    Antlr4ParseEnv<Lexer, Parser, Entry>>(stream, entry);
}


std::string testLangRandomExpr(unsigned numOfOperands);


// Type-Erasure Wrapper
struct TypeErasureWrapper {
  template<typename _Ty>
  TypeErasureWrapper(_Ty src): _inner(new inner<_Ty>(std::forward<_Ty>(src))) {}

  TypeErasureWrapper(const TypeErasureWrapper& src): _inner(src._inner->clone()) {}

  template<typename _Ty>
  TypeErasureWrapper& operator=(_Ty src) {
    _inner = std::make_unique<inner<_Ty>>(std::forward<_Ty>(src));
    return *this;
  }

  TypeErasureWrapper& operator=(const TypeErasureWrapper& src) {
    TypeErasureWrapper oTmp(src);
    std::swap(oTmp._inner, this->_inner);
    return *this;
  }

  struct inner_base {
    using ptr = std::unique_ptr<inner_base>;
    virtual ~inner_base() {}
    virtual inner_base* clone() const = 0;
  };
  template<typename _Ty> struct inner: inner_base {
    inner(_Ty newval): _value(newval) {}
    virtual inner_base* clone() const override {
      return new inner(_value);
    }
  private:
    _Ty _value;
  };

private:
  typename inner_base::ptr _inner;
};

// Wrapper to hold all heap allocated resources that
// used by Environment.
struct HeapResourceHolder: public Utility::TypeErasureWrapper {
  template<typename T>
  HeapResourceHolder(T t):
    Utility::TypeErasureWrapper{t} {}
};

} // Utility

/////////////////////////////////////////////////////////////////////////////
//                               Type Traits                               //
/////////////////////////////////////////////////////////////////////////////
namespace Utility {

template<typename T>
struct is_derefable {
  template<typename U>
  static constexpr std::true_type check(decltype(&U::operator*));

  template<typename>
  static constexpr std::false_type check(...);

  typedef decltype(check<T>(0)) type;

  static constexpr bool value = type::value;
};

template<typename T>
struct is_arrow {
  template<typename U>
  static constexpr std::true_type check(decltype(&U::operator->));

  template<typename>
  static constexpr std::false_type check(...);

  typedef decltype(check<T>(0)) type;

  static constexpr bool value = type::value;
};

template<typename T>
concept Hashable = requires(T a) {
  { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

} // Utility

/////////////////////////////////////////////////////////////////////////////
//                              Code Snippets                              //
/////////////////////////////////////////////////////////////////////////////
namespace Utility {} // Utility


/////////////////////////////////////////////////////////////////////////////
//                            Category Concepts                            //
/////////////////////////////////////////////////////////////////////////////

namespace Utility {

template<template<typename X> class F, typename T>
struct Functor {
  Functor(T a_): a{a_} {}

  virtual std::function<F<T>(F<T>)>
  operator()(std::function<T(T)> f) const = 0;

  T a;
};

/////////////////////////////////////////////////////////////////////////////
//                                  CONFIG                                 //
/////////////////////////////////////////////////////////////////////////////
template<typename T>
struct TypeMapping {
  using type = T;
};

} // Utility

#endif /* UTILITY_H */
