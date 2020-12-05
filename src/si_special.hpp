#pragma once
/// @file   si_special.hpp
/// @brief  Special SI units
#include "si_base.hpp"
#include "si_prefix.hpp"
namespace Si {
namespace Special {
/// @brief Template for applying prefix to gram rather than kilogram. Applying
/// to latter involve some ambiguity because of existing prefix according to
/// standard. Using this alias may improve readability of such application.
/// @tparam Ratio std::ratio representing prefix
/// @tparam T Container type
template <typename Ratio, typename T>
using Gram =
    Internal::Prefix<std::ratio_multiply<std::milli, Ratio>, Base::Kilogram<T>>;
} // namespace Special
} // namespace Si