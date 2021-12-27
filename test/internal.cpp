#include "si_internal.hpp"
#include <gtest/gtest.h>

template <typename T>
using ab = Si::Internal::Unit<T, std::ratio<0>, std::ratio<0>>;

template <typename T>
using Ab = Si::Internal::Unit<T, std::ratio<0>, std::ratio<1>>;
template <typename T>
using aB = Si::Internal::Unit<T, std::ratio<1>, std::ratio<0>>;
template <typename T>
using AB = Si::Internal::Unit<T, std::ratio<1>, std::ratio<1>>;

template <typename T>
using Ab_ = Si::Internal::Unit<T, std::ratio<0>, std::ratio<-1>>;
template <typename T>
using aB_ = Si::Internal::Unit<T, std::ratio<-1>, std::ratio<0>>;
template <typename T>
using AB_ = Si::Internal::Unit<T, std::ratio<-1>, std::ratio<-1>>;

TEST(CoreDeductionLogic, SameUnitSameContainer) {
  ASSERT_EQ(typeid(ab<float>), typeid(ab<float>));
}
TEST(CoreDeductionLogic, SameUnitDifferentContainers) {
  ASSERT_NE(typeid(ab<float>), typeid(ab<double>));
}
TEST(CoreDeductionLogic, Addition) {
  ASSERT_EQ(
      typeid(decltype(std::declval<Ab<float>>() + std::declval<Ab<float>>())),
      typeid(Ab<float>));
}
TEST(CoreDeductionLogic, Subtraction) {
  ASSERT_EQ(
      typeid(decltype(std::declval<aB<float>>() - std::declval<aB<float>>())),
      typeid(aB<float>));
}
TEST(CoreDeductionLogic, AdditionAssignment) {
  ASSERT_EQ(typeid(decltype(std::declval<Ab_<float>>() +=
                            std::declval<Ab_<float>>())),
            typeid(Ab_<float>));
}
TEST(CoreDeductionLogic, SubtractionAssignment) {
  ASSERT_EQ(typeid(decltype(std::declval<aB_<float>>() -=
                            std::declval<aB_<float>>())),
            typeid(aB_<float>));
}
TEST(CoreDeductionLogic, Multiplication) {
  ASSERT_EQ(
      typeid(decltype(std::declval<Ab<float>>() * std::declval<Ab_<float>>())),
      typeid(ab<float>));
}
TEST(CoreDeductionLogic, Division) {
  ASSERT_EQ(
      typeid(decltype(std::declval<AB<float>>() / std::declval<aB<float>>())),
      typeid(Ab<float>));
}
TEST(CoreDeductionLogic, MultiplicationAssignment) {
  ASSERT_EQ(
      typeid(decltype(std::declval<Ab<float>>() *= std::declval<float>())),
      typeid(Ab<float>));
}
TEST(CoreDeductionLogic, DivisionAssignment) {
  ASSERT_EQ(
      typeid(decltype(std::declval<aB<float>>() /= std::declval<float>())),
      typeid(aB<float>));
}
TEST(CoreDeductionLogic, ImplicitContainerConversion) {
  ASSERT_EQ(
      typeid(decltype(std::declval<AB<double>>() * std::declval<AB_<float>>())),
      typeid(ab<double>));
}
TEST(CoreDeductionLogic, UnaryPlusConversion) {
  ASSERT_EQ(typeid(decltype(+std::declval<ab<double>>())), typeid(double));
}
TEST(CoreOperations, Equality) { ASSERT_TRUE(ab<int>(1) == ab<int>(1)); }
TEST(CoreOperations, Inequality) {
  ASSERT_TRUE(Ab<float>(1.0) != Ab<float>(1.5));
}
TEST(CoreOperations, LessOrEqualDifferentValues) {
  ASSERT_TRUE(aB<float>(1.0) <= aB<double>(1.5));
}
TEST(CoreOperations, LessOrEqualSameValue) {
  ASSERT_TRUE(AB<int>(1) <= AB<int>(1));
}
TEST(CoreOperations, Less) { ASSERT_TRUE(ab<float>(1.0) < ab<double>(1.5)); }
TEST(CoreOperations, MoreOrEqualDifferentValues) {
  ASSERT_TRUE(Ab<double>(2.0) >= Ab<double>(1.5));
}
TEST(CoreOperations, MoreOrEqualSameValue) {
  ASSERT_TRUE(aB<int>(2) >= aB<int>(2));
}
TEST(CoreOperations, More) { ASSERT_TRUE(AB<float>(2.0) > AB<float>(1.5)); }
TEST(CoreOperations, Addition) {
  ASSERT_EQ(ab<long long>(1) + ab<int>(2), ab<char>(3));
}
TEST(CoreOperations, AdditionAssignment) {
  ASSERT_EQ(Ab<long long>(1) += Ab<int>(2), Ab<char>(3));
}
TEST(CoreOperations, Subtraction) {
  ASSERT_EQ(aB<int>(1) - aB<char>(2), aB<long long>(-1));
}
TEST(CoreOperations, SubtractionAssignment) {
  ASSERT_EQ(AB<long long>(1) -= AB<int>(2), AB<char>(-1));
}
TEST(CoreOperations, MultiplicationDifferentUnit) {
  ASSERT_EQ(Ab<unsigned long long>(1) * aB<unsigned>(2), AB<unsigned char>(2));
}
TEST(CoreOperations, MultiplicationDifferentContainer) {
  ASSERT_EQ(aB<long>(1) * 3, aB<int>(3));
}
TEST(CoreOperations, MultiplicationAssignment) {
  ASSERT_EQ(AB<unsigned long long>(2) *= 5, AB<char>(10));
}
TEST(CoreOperations, DivisionDifferentUnit) {
  ASSERT_EQ(ab<int>(6) / AB<long>(2), AB_<char>(3));
}
TEST(CoreOperations, DivisionDifferentContainer) {
  ASSERT_EQ(Ab_<long long>(6) / 3, Ab_<unsigned char>(2));
}
TEST(CoreOperations, DivisionAssignment) {
  ASSERT_EQ(aB<unsigned long long>(12) /= 3, aB<unsigned>(4));
}
