#include "../src/si_math.hpp"
#include <stdexcept>

int main() {
  if (typeid(decltype(Si::Math::pow<std::ratio<5, 3>>(
                 std::declval<Si::Internal::Unit<double, std::ratio<3>,
                                                 std::ratio<1, 2>>>())))
          .hash_code() !=
      typeid(Si::Internal::Unit<double, std::ratio<5>, std::ratio<5, 6>>)
          .hash_code())
    throw std::logic_error("Math::pow failed at type deduction");
  if (std::abs(static_cast<double>(Si::Math::pow<std::ratio<1, 2>>(
                   Si::Internal::Unit<double>(2))) -
               std::pow(2.0, 0.5)) > 1e-5)
    throw std::logic_error("Math::pow failed at value calculation");
}