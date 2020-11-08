#pragma once
#include "si_internal.hpp"
namespace Si {
namespace Base {
template <typename T> using Meter = Internal::Unit<T, 1, 0, 0, 0, 0, 0, 0>;
template <typename T> using Kilogram = Internal::Unit<T, 0, 1, 0, 0, 0, 0, 0>;
template <typename T> using Second = Internal::Unit<T, 0, 0, 1, 0, 0, 0, 0>;
template <typename T> using Ampere = Internal::Unit<T, 0, 0, 0, 1, 0, 0, 0>;
template <typename T> using Kelvin = Internal::Unit<T, 0, 0, 0, 0, 1, 0, 0>;
template <typename T> using Mole = Internal::Unit<T, 0, 0, 0, 0, 0, 1, 0>;
template <typename T> using Candela = Internal::Unit<T, 0, 0, 0, 0, 0, 0, 1>;
namespace Literals {
Meter<long double> operator"" _m(long double value) {
  return Meter<long double>(value);
}
Kilogram<long double> operator"" _kg(long double value) {
  return Kilogram<long double>(value);
}
Second<long double> operator"" _s(long double value) {
  return Second<long double>(value);
}
Ampere<long double> operator"" _A(long double value) {
  return Ampere<long double>(value);
}
Kelvin<long double> operator"" _K(long double value) {
  return Kelvin<long double>(value);
}
Mole<long double> operator"" _mol(long double value) {
  return Mole<long double>(value);
}
Candela<long double> operator"" _cd(long double value) {
  return Candela<long double>(value);
}
} // namespace Literals
} // namespace Base
} // namespace Si
