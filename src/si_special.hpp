#pragma once
/// @file   si_special.hpp
/// @brief  Special SI units
#include "si_base.hpp"
#include "si_prefix.hpp"
namespace Si {
namespace Special {
/// @brief Template for applying prefix to gram rather than kilogram. Applying
/// to latter involve some ambiguity because of existing prefix according to
/// standard.
/// @tparam Ratio std::ratio representing prefix
/// @tparam T Container type
template <typename T> struct Gram {
  template <typename Ratio>
  using type =
      Si::Prefix<std::ratio_multiply<std::milli, Ratio>, Base::Kilogram<T>>;
}; // namespace Special
} // namespace Special
} // namespace Si