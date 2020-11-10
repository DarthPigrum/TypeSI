#include "../src/si_base.hpp"
#include <stdexcept>

using namespace Si::Base::Literals;

int main() {
  if (typeid(decltype(1.0_m)).hash_code() !=
      typeid(Si::Base::Meter<long double>).hash_code())
    throw std::logic_error("Meter literal failed");
  if (typeid(decltype(1.0_kg)).hash_code() !=
      typeid(Si::Base::Kilogram<long double>).hash_code())
    throw std::logic_error("Kilogram literal failed");
  if (typeid(decltype(1.0_s)).hash_code() !=
      typeid(Si::Base::Second<long double>).hash_code())
    throw std::logic_error("Second literal failed");
  if (typeid(decltype(1.0_A)).hash_code() !=
      typeid(Si::Base::Ampere<long double>).hash_code())
    throw std::logic_error("Ampere literal failed");
  if (typeid(decltype(1.0_K)).hash_code() !=
      typeid(Si::Base::Kelvin<long double>).hash_code())
    throw std::logic_error("Kelvin literal failed");
  if (typeid(decltype(1.0_mol)).hash_code() !=
      typeid(Si::Base::Mole<long double>).hash_code())
    throw std::logic_error("Mole literal failed");
  if (typeid(decltype(1.0_cd)).hash_code() !=
      typeid(Si::Base::Candela<long double>).hash_code())
    throw std::logic_error("Candela literal failed");
}