#include "../src/si_derived.hpp"
#include <stdexcept>

using namespace Si::Base::Literals;
using namespace Si::Derived::Literals;

int main() {
  if (typeid(decltype(Si::Internal::Dimensionless<long double>(1) / 1.0_s))
          .hash_code() != typeid(decltype(1.0_Hz)).hash_code())
    throw std::logic_error("Hertz unit failed");
  if (typeid(decltype(1.0_kg * 2.0_m / (3.0_s * 4.0_s))).hash_code() !=
      typeid(decltype(1.0_N)).hash_code())
    throw std::logic_error("Newton unit failed");
  if (typeid(decltype(1.0_N / (2.0_m * 3.0_m))).hash_code() !=
      typeid(decltype(1.0_Pa)).hash_code())
    throw std::logic_error("Pascal unit failed");
  if (typeid(decltype(1.0_m * 2.0_N)).hash_code() !=
      typeid(decltype(1.0_J)).hash_code())
    throw std::logic_error("Joule unit failed");
  if (typeid(decltype(1.0_J / 2.0_s)).hash_code() !=
      typeid(decltype(1.0_W)).hash_code())
    throw std::logic_error("Watt unit failed");
  if (typeid(decltype(1.0_s * 2.0_A)).hash_code() !=
      typeid(decltype(1.0_C)).hash_code())
    throw std::logic_error("Coulomb unit failed");
  if (typeid(decltype(1.0_W / 2.0_A)).hash_code() !=
      typeid(decltype(1.0_V)).hash_code())
    throw std::logic_error("Volt unit failed");
  if (typeid(decltype(1.0_C / 2.0_V)).hash_code() !=
      typeid(decltype(1.0_F)).hash_code())
    throw std::logic_error("Farad unit failed");
  if (typeid(decltype(1.0_V / 2.0_A)).hash_code() !=
      typeid(decltype(1.0_Ohm)).hash_code())
    throw std::logic_error("Ohm unit failed");
  if (typeid(decltype(1.0_A / 2.0_V)).hash_code() !=
      typeid(decltype(1.0_S)).hash_code())
    throw std::logic_error("Siemens unit failed");
  if (typeid(decltype(1.0_J / 2.0_A)).hash_code() !=
      typeid(decltype(1.0_Wb)).hash_code())
    throw std::logic_error("Weber unit failed");
  if (typeid(decltype(1.0_Wb / (2.0_m * 3.0_m))).hash_code() !=
      typeid(decltype(1.0_T)).hash_code())
    throw std::logic_error("Tesla unit failed");
  if (typeid(decltype(1.0_Wb / 2.0_A)).hash_code() !=
      typeid(decltype(1.0_H)).hash_code())
    throw std::logic_error("Henry unit failed");
  if (typeid(decltype(1.0_cd)).hash_code() !=
      typeid(decltype(1.0_lm)).hash_code())
    throw std::logic_error("Lumen unit failed");
  if (typeid(decltype(1.0_lm / (2.0_m * 3.0_m))).hash_code() !=
      typeid(decltype(1.0_lx)).hash_code())
    throw std::logic_error("Lux unit failed");
  if (typeid(decltype(1.0_Hz)).hash_code() !=
      typeid(decltype(1.0_Bq)).hash_code())
    throw std::logic_error("Becquerel unit failed");
  if (typeid(decltype(1.0_J / 2.0_kg)).hash_code() !=
      typeid(decltype(1.0_Gy)).hash_code())
    throw std::logic_error("Gray unit failed");
  if (typeid(decltype(1.0_J / 2.0_kg)).hash_code() !=
      typeid(decltype(1.0_Sv)).hash_code())
    throw std::logic_error("Sievert unit failed");
  if (typeid(decltype(1.0_mol / 2.0_s)).hash_code() !=
      typeid(decltype(1.0_kat)).hash_code())
    throw std::logic_error("Katal unit failed");
}