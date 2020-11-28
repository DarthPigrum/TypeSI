#pragma once
/// @file   si_prefix.hpp
/// @brief  Prefixes for SI units
#include "si_utilities.hpp"
#include <ratio>
#include <utility>
namespace Si {
/// @brief Generic type of unit with prefix
/// @tparam Ratio std::ratio representing prefix
/// @tparam Unit Templated class of SI unit
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename Ratio, typename Unit> class Prefix {
  using T = decltype(+std::declval<Unit>());

public:
  Unit _unit;
  /// @brief Explicit constructor from container type
  explicit Prefix(const T &value) : _unit(value){};
  /// @brief Implicit constructor from same units with different container type
  template <typename AnotherUnit>
  Prefix(const Prefix<Ratio, AnotherUnit> &unit)
      : _unit(Internal::convertImplicitly<Unit>(unit._unit)){};
  /// @brief Constructor from Unit type(implicit by default, can be made
  /// explicit by TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS macro)
  template <typename AnotherUnit,
            typename std::enable_if<
                !std::is_same<AnotherUnit,
                              decltype(+std::declval<AnotherUnit>())>::value,
                int>::type = 0>
#ifdef TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS
  explicit
#endif
      Prefix(const AnotherUnit &unit)
      : _unit(Internal::convertImplicitly<Unit>(unit) *
              static_cast<T>(Ratio::den) / static_cast<T>(Ratio::num)){};
  /// @brief Explicit constructor from unit with different prefix(implicit by
  /// default, can be made explicit by
  /// TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS macro)
  template <typename AnotherRatio, typename AnotherUnit>
#ifdef TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS
  explicit
#endif
      Prefix(const Prefix<AnotherRatio, AnotherUnit> &unit)
      : _unit(Internal::convertImplicitly<AnotherUnit>(unit._unit) *
              static_cast<T>(std::ratio_divide<AnotherRatio, Ratio>::num) /
              static_cast<T>(std::ratio_divide<AnotherRatio, Ratio>::den)){};
  /// @brief Conversion to container type via unary '+'
  T operator+() const { return +_unit; }
  /// @brief Operator '=='
  template <typename U>
  decltype(std::declval<Unit>() == std::declval<Unit>())
  operator==(const U &unit) const {
    return _unit == Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '!='
  template <typename U>
  decltype(std::declval<Unit>() != std::declval<Unit>())
  operator!=(const U &unit) const {
    return _unit != Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '<'
  template <typename U>
  decltype(std::declval<Unit>() < std::declval<Unit>())
  operator<(const U &unit) const {
    return _unit < Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '<='
  template <typename U>
  decltype(std::declval<Unit>() <= std::declval<Unit>())
  operator<=(const U &unit) const {
    return _unit <= Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '>'
  template <typename U>
  decltype(std::declval<Unit>() > std::declval<Unit>())
  operator>(const U &unit) const {
    return _unit > Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '>='
  template <typename U>
  decltype(std::declval<Unit>() >= std::declval<Unit>())
  operator>=(const U &unit) const {
    return _unit >= Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
};
} // namespace Si