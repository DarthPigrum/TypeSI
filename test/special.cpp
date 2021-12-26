#include "si_base.hpp"
#include "si_prefix.hpp"
#include "si_special.hpp"
#include <gtest/gtest.h>

TEST(SpecialUnits, Gram) {
  EXPECT_EQ(typeid(Si::Prefix<std::milli, Si::Special::Gram<double>>),
            typeid(Si::Prefix<std::micro, Si::Base::Kilogram<double>>));
}