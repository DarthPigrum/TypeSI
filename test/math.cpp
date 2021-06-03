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
  if (typeid(
          decltype(Si::Math::pow<std::ratio<3>>(
              std::declval<Si::Prefix<
                  std::ratio<5, 3>, Si::Internal::Unit<double, std::ratio<3>,
                                                       std::ratio<1, 2>>>>())))
          .hash_code() !=
      typeid(Si::Prefix<
                 std::ratio<125, 27>,
                 Si::Internal::Unit<double, std::ratio<9>, std::ratio<3, 2>>>)
          .hash_code())
    throw std::logic_error(
        "Math::pow failed at type deduction for unit with prefix");
  if (std::abs(+Si::Math::pow<std::ratio<3>>(
                   Si::Prefix<std::ratio<5, 3>,
                              Si::Internal::Unit<double, std::ratio<3>,
                                                 std::ratio<1, 2>>>(1.5)) -
               std::pow(1.5, 3)) > 1e-5)
    throw std::logic_error("Math::pow failed at value calculation with prefix");
}