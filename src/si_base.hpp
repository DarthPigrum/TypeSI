#pragma once
/**
 *  @file   si_base.hpp
 *  @brief  Base SI units
 *  @author Mike Zhukov
 ***********************************************/
#include "si_internal.hpp"
namespace Si {
/// @brief Base SI units
namespace Base {
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Meter =
    Internal::Unit<T, std::ratio<1>, std::ratio<0>, std::ratio<0>,
                   std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Kilogram =
    Internal::Unit<T, std::ratio<0>, std::ratio<1>, std::ratio<0>,
                   std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Second =
    Internal::Unit<T, std::ratio<0>, std::ratio<0>, std::ratio<1>,
                   std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Ampere =
    Internal::Unit<T, std::ratio<0>, std::ratio<0>, std::ratio<0>,
                   std::ratio<1>, std::ratio<0>, std::ratio<0>, std::ratio<0>>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Kelvin =
    Internal::Unit<T, std::ratio<0>, std::ratio<0>, std::ratio<0>,
                   std::ratio<0>, std::ratio<1>, std::ratio<0>, std::ratio<0>>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Mole =
    Internal::Unit<T, std::ratio<0>, std::ratio<0>, std::ratio<0>,
                   std::ratio<0>, std::ratio<0>, std::ratio<1>, std::ratio<0>>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Candela =
    Internal::Unit<T, std::ratio<0>, std::ratio<0>, std::ratio<0>,
                   std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<1>>;
/// @brief Use this namespace to enable literals for base units
namespace Literals {
/// @brief _m long double literal for meter
Meter<long double> operator"" _m(long double value) {
  return Meter<long double>(value);
}
/// @brief _kg long double literal for kilogram
Kilogram<long double> operator"" _kg(long double value) {
  return Kilogram<long double>(value);
}
/// @brief _s long double literal for second
Second<long double> operator"" _s(long double value) {
  return Second<long double>(value);
}
/// @brief _A long double literal for ampere
Ampere<long double> operator"" _A(long double value) {
  return Ampere<long double>(value);
}
/// @brief _K long double literal for kelvin
Kelvin<long double> operator"" _K(long double value) {
  return Kelvin<long double>(value);
}
/// @brief _mol long double literal for mole
Mole<long double> operator"" _mol(long double value) {
  return Mole<long double>(value);
}
/// @brief _cd long double literal for candela
Candela<long double> operator"" _cd(long double value) {
  return Candela<long double>(value);
}
} // namespace Literals
} // namespace Base
} // namespace Si
