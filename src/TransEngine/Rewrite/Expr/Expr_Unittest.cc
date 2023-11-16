#include <gtest/gtest.h>
#include <memory>
#include "Expr.h"


namespace TransEngine {
namespace Expression {

TEST(ExpressionTest, Value) {
  Unit<int> u1, u2;
  Bool<int> v1{true}, v2{false}, v3{true};

  // Check Value operator==
  EXPECT_TRUE(u1 != AS_VALUE(v1, int));
  EXPECT_TRUE(u2 != AS_VALUE(v1, int));
  EXPECT_TRUE(u1 == u2);

  EXPECT_TRUE(v1 != v2);
  EXPECT_TRUE(v1 == v3);
}

TEST(ExpressionTest, ConstExpression) {
  // Unit
  Constant<int> a{std::make_unique<Unit<int>>()};
  EXPECT_TRUE(*(a(nullptr)) == Unit<int>{});
  EXPECT_TRUE(*(a(nullptr)) != Bool<int>{});
  EXPECT_TRUE(*(a(nullptr)) == *(a(nullptr)));

  // Bool
  Constant<int> b{std::make_unique<Bool<int>>()};
  EXPECT_TRUE(*(b(nullptr)) != Unit<int>{});
  EXPECT_TRUE(*(b(nullptr)) == Bool<int>{});
  EXPECT_TRUE(*(b(nullptr)) == *(b(nullptr)));
}

TEST(ExpressionTest, EqualExpression) {
  // Expression () = () which should result
  // in True.
  Equal<int> a{
    std::make_unique<Constant<int>>(
      std::make_unique<Unit<int>>()),
    std::make_unique<Constant<int>>(
      std::make_unique<Unit<int>>())};
  EXPECT_TRUE(Bool<int>{true} == *a(nullptr));

  // Expression () = T which should result
  // in False.
  Equal<int> b{
    std::make_unique<Constant<int>>(
      std::make_unique<Unit<int>>()),
    std::make_unique<Constant<int>>(
      std::make_unique<Bool<int>>(true))};
  EXPECT_TRUE(Bool<int>{false} == *b(nullptr));
}

// This function will checkging whether all of
// it's arguments has same type.
struct CheckEquality: public Function<int> {
  std::unique_ptr<Value<int>> operator()(Arguments<int>* args) override {

    Value<int>& first = *args->args[0];
    for (auto& c: args->args) {
      if (!IS_SAME_TYPE(first, *c)) {
        return std::make_unique<Bool<int>>(false);
      }
    }

    return std::make_unique<Bool<int>>(true);
  }
};

TEST(ExpressionTest, CallExpression) {
  // Build up arguments
  std::vector<std::unique_ptr<Expr<int>>> args;

  args.emplace_back(
    // Constant Expression
    std::make_unique<Constant<int>>(
      std::make_unique<Unit<int>>())
  );

  args.emplace_back(
    // Constant Expression
    std::make_unique<Constant<int>>(
      std::make_unique<Unit<int>>())
  );

  // GenUnit is a Chameleons function
  Call<int> c{
    std::make_unique<CheckEquality>(),
    std::move(args) };

  // Got a Value once you evaluate the function.
  std::unique_ptr<Value<int>> v = c(nullptr);

  EXPECT_TRUE(*v == Bool<int>{true});
}

TEST(ExpressionTest, CallExpression_FalseCase) {
  // Build up arguments
  std::vector<std::unique_ptr<Expr<int>>> args;

  args.emplace_back(
    // Constant Expression
    std::make_unique<Constant<int>>(
      std::make_unique<Unit<int>>())
  );

  args.emplace_back(
    // Constant Expression
    std::make_unique<Constant<int>>(
      std::make_unique<Bool<int>>())
  );
  // GenUnit is a Chameleons function
  Call<int> c{
    std::make_unique<CheckEquality>(),
    std::move(args) };

  // Got a Value once you evaluate the function.
  std::unique_ptr<Value<int>> v = c(nullptr);

  EXPECT_TRUE(*v == Bool<int>{false});

}

} // Expression
} // TransEngine