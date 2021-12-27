#include "si_derived.hpp"
#include <gtest/gtest.h>

using namespace Si::Base::Literals;
using namespace Si::Derived::Literals;

TEST(DerivedUnits, Hertz) {
  ASSERT_EQ(
      typeid(decltype(Si::Internal::Dimensionless<long double>(1) / 1.0_s)),
      typeid(decltype(1.0_Hz)));
}
TEST(DerivedUnits, Newton) {
  ASSERT_EQ(typeid(decltype(1.0_kg * 2.0_m / (3.0_s * 4.0_s))),
            typeid(decltype(1.0_N)));
}
TEST(DerivedUnits, Pascal) {
  ASSERT_EQ(typeid(decltype(1.0_N / (2.0_m * 3.0_m))),
            typeid(decltype(1.0_Pa)));
}
TEST(DerivedUnits, Joule) {
  ASSERT_EQ(typeid(decltype(1.0_m * 2.0_N)), typeid(decltype(1.0_J)));
}
TEST(DerivedUnits, Watt) {
  ASSERT_EQ(typeid(decltype(1.0_J / 2.0_s)), typeid(decltype(1.0_W)));
}
TEST(DerivedUnits, Coulomb) {
  ASSERT_EQ(typeid(decltype(1.0_s * 2.0_A)), typeid(decltype(1.0_C)));
}
TEST(DerivedUnits, Volt) {
  ASSERT_EQ(typeid(decltype(1.0_W / 2.0_A)), typeid(decltype(1.0_V)));
}
TEST(DerivedUnits, Farad) {
  ASSERT_EQ(typeid(decltype(1.0_C / 2.0_V)), typeid(decltype(1.0_F)));
}
TEST(DerivedUnits, Ohm) {
  ASSERT_EQ(typeid(decltype(1.0_V / 2.0_A)), typeid(decltype(1.0_Ohm)));
}
TEST(DerivedUnits, Siemens) {
  ASSERT_EQ(typeid(decltype(1.0_A / 2.0_V)), typeid(decltype(1.0_S)));
}
TEST(DerivedUnits, Weber) {
  ASSERT_EQ(typeid(decltype(1.0_J / 2.0_A)), typeid(decltype(1.0_Wb)));
}
TEST(DerivedUnits, Tesla) {
  ASSERT_EQ(typeid(decltype(1.0_Wb / (2.0_m * 3.0_m))),
            typeid(decltype(1.0_T)));
}
TEST(DerivedUnits, Henry) {
  ASSERT_EQ(typeid(decltype(1.0_Wb / 2.0_A)), typeid(decltype(1.0_H)));
}
TEST(DerivedUnits, Lumen) {
  ASSERT_EQ(typeid(decltype(1.0_cd)), typeid(decltype(1.0_lm)));
}
TEST(DerivedUnits, Lux) {
  ASSERT_EQ(typeid(decltype(1.0_lm / (2.0_m * 3.0_m))),
            typeid(decltype(1.0_lx)));
}
TEST(DerivedUnits, Becquerel) {
  ASSERT_EQ(typeid(decltype(1.0_Hz)), typeid(decltype(1.0_Bq)));
}
TEST(DerivedUnits, Gray) {
  ASSERT_EQ(typeid(decltype(1.0_J / 2.0_kg)), typeid(decltype(1.0_Gy)));
}
TEST(DerivedUnits, Sievert) {
  ASSERT_EQ(typeid(decltype(1.0_J / 2.0_kg)), typeid(decltype(1.0_Sv)));
}
TEST(DerivedUnits, Katal) {
  ASSERT_EQ(typeid(decltype(1.0_mol / 2.0_s)), typeid(decltype(1.0_kat)));
}