#pragma once
/// @file   si_derived.hpp
/// @brief  Derived SI units
#include "si_base.hpp"
#include <utility>
namespace Si {
/// @brief Derived SI units
namespace Derived {
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Hertz = decltype(std::declval<Internal::Dimensionless<T>>() /
                       std::declval<Base::Second<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Newton = decltype(
    std::declval<Base::Kilogram<T>>() * std::declval<Base::Meter<T>>() /
    (std::declval<Base::Second<T>>() * std::declval<Base::Second<T>>()));
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Pascal =
    decltype(std::declval<Newton<T>>() /
             (std::declval<Base::Meter<T>>() * std::declval<Base::Meter<T>>()));
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Joule =
    decltype(std::declval<Base::Meter<T>>() * std::declval<Newton<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Watt =
    decltype(std::declval<Joule<T>>() / std::declval<Base::Second<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Coulomb =
    decltype(std::declval<Base::Second<T>>() * std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Volt =
    decltype(std::declval<Watt<T>>() / std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Farad = decltype(std::declval<Coulomb<T>>() / std::declval<Volt<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Ohm = decltype(std::declval<Volt<T>>() / std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Siemens =
    decltype(std::declval<Base::Ampere<T>>() / std::declval<Volt<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Weber =
    decltype(std::declval<Joule<T>>() / std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Tesla =
    decltype(std::declval<Newton<T>>() / (std::declval<Base::Ampere<T>>() *
                                          std::declval<Base::Meter<T>>()));
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Henry =
    decltype(std::declval<Weber<T>>() / std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Lumen = Base::Candela<T>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Lux =
    decltype(std::declval<Lumen<T>>() /
             (std::declval<Base::Meter<T>>() * std::declval<Base::Meter<T>>()));
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Becquerel = Hertz<T>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Gray =
    decltype(std::declval<Joule<T>>() / std::declval<Base::Kilogram<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Sievert = Gray<T>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Katal =
    decltype(std::declval<Base::Mole<T>>() / std::declval<Base::Second<T>>());
/// @brief Use this namespace to enable literals for base units
namespace Literals {
/// @brief _m long double literal for hertz
Hertz<long double> operator"" _Hz(long double value) {
  return Hertz<long double>(value);
}
/// @brief _kg long double literal for newton
Newton<long double> operator"" _N(long double value) {
  return Newton<long double>(value);
}
/// @brief _s long double literal for pascal
Pascal<long double> operator"" _Pa(long double value) {
  return Pascal<long double>(value);
}
/// @brief _A long double literal for joule
Joule<long double> operator"" _J(long double value) {
  return Joule<long double>(value);
}
/// @brief _K long double literal for watt
Watt<long double> operator"" _W(long double value) {
  return Watt<long double>(value);
}
/// @brief _mol long double literal for coulomb
Coulomb<long double> operator"" _C(long double value) {
  return Coulomb<long double>(value);
}
/// @brief _cd long double literal for volt
Volt<long double> operator"" _V(long double value) {
  return Volt<long double>(value);
}
/// @brief _cd long double literal for farad
Farad<long double> operator"" _F(long double value) {
  return Farad<long double>(value);
}
/// @brief _cd long double literal for ohm(not as defined by standard because of
/// non-ASCII symbol)
Ohm<long double> operator"" _Ohm(long double value) {
  return Ohm<long double>(value);
}
/// @brief _cd long double literal for siemens
Siemens<long double> operator"" _S(long double value) {
  return Siemens<long double>(value);
}
/// @brief _cd long double literal for weber
Weber<long double> operator"" _Wb(long double value) {
  return Weber<long double>(value);
}
/// @brief _cd long double literal for tesla
Tesla<long double> operator"" _T(long double value) {
  return Tesla<long double>(value);
}
/// @brief _cd long double literal for henry
Henry<long double> operator"" _H(long double value) {
  return Henry<long double>(value);
}
/// @brief _cd long double literal for lumen
Lumen<long double> operator"" _lm(long double value) {
  return Lumen<long double>(value);
}
/// @brief _cd long double literal for lux
Lux<long double> operator"" _lx(long double value) {
  return Lux<long double>(value);
}
/// @brief _cd long double literal for becquerel
Becquerel<long double> operator"" _Bq(long double value) {
  return Becquerel<long double>(value);
}
/// @brief _cd long double literal for gray
Gray<long double> operator"" _Gy(long double value) {
  return Gray<long double>(value);
}
/// @brief _cd long double literal for sievert
Sievert<long double> operator"" _Sv(long double value) {
  return Sievert<long double>(value);
}
/// @brief _cd long double literal for katal
Katal<long double> operator"" _kat(long double value) {
  return Katal<long double>(value);
}
} // namespace Literals
} // namespace Derived
} // namespace Si
