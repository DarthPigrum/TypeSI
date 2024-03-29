#include "si_math.hpp"
#include <gtest/gtest.h>

TEST(Math, PowDeduction) {
  ASSERT_EQ(
      typeid(decltype(Si::Math::pow<std::ratio<5, 3>>(
          std::declval<
              Si::Internal::Unit<double, std::ratio<3>, std::ratio<1, 2>>>()))),
      typeid(Si::Internal::Unit<double, std::ratio<5>, std::ratio<5, 6>>));
}
TEST(Math, PowCalculation) {
  ASSERT_NEAR(static_cast<double>(Si::Math::pow<std::ratio<1, 2>>(
                  Si::Internal::Unit<double>(2))),
              std::pow(2.0, 0.5), 1e-5);
}
TEST(Math, PowPrefixDeduction) {
  ASSERT_EQ(
      typeid(decltype(Si::Math::pow<std::ratio<3>>(
          std::declval<Si::Prefix<std::ratio<5, 3>,
                                  Si::Internal::Unit<double, std::ratio<3>,
                                                     std::ratio<1, 2>>>>()))),
      typeid(Si::Prefix<
             std::ratio<125, 27>,
             Si::Internal::Unit<double, std::ratio<9>, std::ratio<3, 2>>>));
}
TEST(Math, PowPrefixCalculation) {
  ASSERT_NEAR(
      +Si::Math::pow<std::ratio<3>>(
          Si::Prefix<std::ratio<5, 3>, Si::Internal::Unit<double, std::ratio<3>,
                                                          std::ratio<1, 2>>>(
              1.5)),
      std::pow(1.5, 3), 1e-5);
}