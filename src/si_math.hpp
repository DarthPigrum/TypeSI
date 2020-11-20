#pragma once
/// @file   si_math.hpp
/// @brief  Mathematical operations with Si units
#include "si_internal.hpp"
#include <cmath>
namespace Si {
namespace Internal {
template <typename T> struct std_pow {
  T operator()(const T &base, const T &power) const {
    return std::pow(base, power);
  }
};
} // namespace Internal
/// @brief Mathematical operations with Si units
namespace Math {
/// @brief Function for exponentiation with Unit as base
/// @tparam Power std::ratio representing power
/// @tparam T (optional) Container type for Unit
/// @tparam Function (optional) Class with operator() defined as pow function
/// for container type
/// @tparam Powers (optional) Sequence of std::ratio from Unit argument(supposed
/// to always be filled by the compiler)
template <typename Power, typename T, typename Function = Internal::std_pow<T>,
          typename... Powers>
Internal::Unit<T, std::ratio_multiply<Power, Powers>...>
pow(const Internal::Unit<T, Powers...> &base) {
  return Internal::Unit<T, std::ratio_multiply<Power, Powers>...>(
      Function()(static_cast<T>(base),
                 static_cast<T>(Power::num) / static_cast<T>(Power::den)));
}
} // namespace Math
} // namespace Si