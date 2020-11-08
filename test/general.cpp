#include "../src/si.hpp"
#include <iostream>
#include <utility>

int main() {
  using namespace Si::Base::Literals;
  using Force = decltype(std::declval<Si::Base::Kilogram<double>>() *
                         (std::declval<Si::Base::Meter<double>>() /
                          (std::declval<Si::Base::Second<double>>() *
                           std::declval<Si::Base::Second<double>>())));
  auto acc = 9.8_m / (1.0_s * 1.0_s);
  if (typeid(Force).hash_code() !=
      typeid(decltype(std::declval<Si::Base::Kilogram<double>>() * acc))
          .hash_code())
    throw std::logic_error("Type error");
  Force force = (42.0_kg * acc) / 2;
  force *= 1.5;
  force += force;
  if ((double)force - (42.0 * 9.8 / 2) * 1.5 * 2 > 1e-5)
    throw std::logic_error("Calculation error");
  return 0;
}
