#include "../src/si_base.hpp"
#include "../src/si_prefix.hpp"
#include "../src/si_special.hpp"
#include <stdexcept>

int main() {
  if (typeid(Si::Prefix<std::milli, Si::Special::Gram<double>>).hash_code() !=
      typeid(Si::Prefix<std::micro, Si::Base::Kilogram<double>>).hash_code())
    throw std::logic_error("Wrong type deduction for Gram template type");
}