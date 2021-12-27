#include "si_base.hpp"
#include <gtest/gtest.h>

using namespace Si::Base::Literals;

TEST(BaseUnits, Meter) {
  ASSERT_EQ(typeid(decltype(1.0_m)), typeid(Si::Base::Meter<long double>));
}
TEST(BaseUnits, Kilogram) {
  ASSERT_EQ(typeid(decltype(1.0_kg)), typeid(Si::Base::Kilogram<long double>));
}
TEST(BaseUnits, Second) {
  ASSERT_EQ(typeid(decltype(1.0_s)), typeid(Si::Base::Second<long double>));
}
TEST(BaseUnits, Ampere) {
  ASSERT_EQ(typeid(decltype(1.0_A)), typeid(Si::Base::Ampere<long double>));
}
TEST(BaseUnits, Kelvin) {
  ASSERT_EQ(typeid(decltype(1.0_K)), typeid(Si::Base::Kelvin<long double>));
}
TEST(BaseUnits, Mole) {
  ASSERT_EQ(typeid(decltype(1.0_mol)), typeid(Si::Base::Mole<long double>));
}
TEST(BaseUnits, Candela) {
  ASSERT_EQ(typeid(decltype(1.0_cd)), typeid(Si::Base::Candela<long double>));
}