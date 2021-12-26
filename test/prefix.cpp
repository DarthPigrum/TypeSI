#include "si_internal.hpp"
#include "si_prefix.hpp"
#include <gtest/gtest.h>

template <typename T>
using u0 = Si::Internal::Unit<T, std::ratio<0>, std::ratio<0>>;
template <typename T> using mu0 = Si::Prefix<std::milli, u0<T>>;
template <typename T> using ku0 = Si::Prefix<std::kilo, u0<T>>;

template <typename T>
using u1 = Si::Internal::Unit<T, std::ratio<1>, std::ratio<0>>;
template <typename T> using mu1 = Si::Prefix<std::milli, u1<T>>;
template <typename T> using ku1 = Si::Prefix<std::kilo, u1<T>>;

template <typename T>
using u2 = Si::Internal::Unit<T, std::ratio<0>, std::ratio<1>>;
template <typename T> using mu2 = Si::Prefix<std::milli, u2<T>>;
template <typename T> using ku2 = Si::Prefix<std::kilo, u2<T>>;

template <typename T>
using u3 = Si::Internal::Unit<T, std::ratio<1>, std::ratio<1>>;
template <typename T> using mu3 = Si::Prefix<std::milli, u3<T>>;
template <typename T> using ku3 = Si::Prefix<std::kilo, u3<T>>;

TEST(Prefix, SameContainerSameValue) {
  ASSERT_TRUE(mu1<int>(1) == mu1<int>(1));
  ASSERT_FALSE(mu1<int>(1) != mu1<int>(1));
}
TEST(Prefix, SameContainerDifferentValues) {
  ASSERT_FALSE(mu1<int>(1000) == mu1<int>(1));
  ASSERT_TRUE(mu1<int>(1000) != mu1<int>(1));
}
TEST(Prefix, DifferentContainerSameValue) {
  ASSERT_TRUE(mu1<int>(1) == mu1<char>(1));
  ASSERT_FALSE(mu1<int>(1) != mu1<char>(1));
}
TEST(Prefix, DifferentContainerDifferentValue) {
  ASSERT_FALSE(mu1<int>(1000) == mu1<long>(1));
  ASSERT_TRUE(mu1<int>(1000) != mu1<long>(1));
}
TEST(Prefix, NoPrefixSameValue) {
  ASSERT_TRUE(mu1<int>(1000) == u1<int>(1));
  ASSERT_FALSE(mu1<int>(1000) != u1<int>(1));
}
TEST(Prefix, NoPrefixDifferentValue) {
  ASSERT_FALSE(mu1<int>(1000000) == u1<int>(1));
  ASSERT_TRUE(mu1<int>(1000000) != u1<int>(1));
}
TEST(Prefix, DifferentPrefixSameValue) {
  ASSERT_TRUE(mu1<long>(1000000) == ku1<int>(1));
  ASSERT_FALSE(mu1<long>(1000000) != ku1<int>(1));
}
TEST(Prefix, DifferentPrefixDifferentValue) {
  ASSERT_FALSE(mu1<long long>(1000) == ku1<long>(1));
  ASSERT_TRUE(mu1<long long>(1000) != ku1<long>(1));
}
TEST(Prefix, Less) {
  ASSERT_TRUE(mu1<float>(10.0) < ku1<double>(0.1));
  ASSERT_FALSE(mu1<float>(100000.0) < ku1<double>(0.01));
}
TEST(Prefix, LessOrEqual) {
  ASSERT_TRUE(mu1<float>(10.0) <= ku1<double>(0.1));
  ASSERT_FALSE(mu1<float>(100000.0) <= ku1<double>(0.01));
}
TEST(Prefix, More) {
  ASSERT_TRUE(ku1<float>(1.0) > u1<double>(0.1));
  ASSERT_FALSE(mu1<float>(1.0) > ku1<double>(1.0));
}
TEST(Prefix, MoreOrEqual) {
  ASSERT_TRUE(ku1<float>(1.0) >= mu1<double>(100.0));
  ASSERT_FALSE(mu1<float>(10.0) >= ku1<double>(10.0));
}
TEST(Prefix, Addition) {
  ASSERT_EQ(mu1<int>(100) + ku1<long>(1), mu1<long long>(1000100));
}
TEST(Prefix, AdditionAssignment) {
  ASSERT_EQ(mu1<int>(100) += ku1<long>(1), mu1<long long>(1000100));
}
TEST(Prefix, Subtraction) {
  ASSERT_EQ(mu1<long>(1100) - u1<int>(1), mu1<long long>(100));
}
TEST(Prefix, SubtractionAssignement) {
  ASSERT_EQ(mu1<long>(1100) -= u1<int>(1), mu1<long long>(100));
}
TEST(Prefix, MultiplicationPrefix) {
  ASSERT_EQ(mu1<int>(10) * ku2<long>(1), u3<long long>(10));
}
TEST(Prefix, MultiplicationNoPrefix) {
  ASSERT_EQ(mu1<int>(100) * u2<long>(1), mu3<long long>(100));
}
TEST(Prefix, MultiplicationAssignement) {
  ASSERT_EQ(mu1<int>(10) *= 10, mu1<long long>(100));
}
TEST(Prefix, DivisionPrefix) {
  ASSERT_EQ(ku1<int>(10) / ku1<long>(1), u0<long long>(10));
}
TEST(Prefix, DivisionAssignement) {
  ASSERT_EQ(mu2<int>(100) /= 10, mu2<long long>(10));
}