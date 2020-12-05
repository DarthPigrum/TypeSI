#pragma once
/// @file   si_prefix.hpp
/// @brief  Prefixes for SI units
#include "si_utilities.hpp"
#include <ratio>
#include <utility>
namespace Si {
namespace Internal {
/// @brief Generic type of unit with prefix
/// @tparam Ratio std::ratio representing prefix
/// @tparam Unit Templated class of SI unit
template <typename Ratio, typename Unit> class Prefix {
  using T = decltype(+std::declval<Unit>());
  Unit _unit;

public:
  /// @brief Getter for raw Unit reference without prefix applied
  const Unit &raw() const { return _unit; }
  /// @brief Explicit constructor from container type
  explicit Prefix(const T &value) : _unit(value) {}
  /// @brief Implicit constructor from same units with different container type
  template <typename AnotherUnit,
            typename std::enable_if<
                std::is_convertible<AnotherUnit, Unit>::value, int>::type = 0>
  Prefix(const Prefix<Ratio, AnotherUnit> &unit)
      : _unit(Internal::convertImplicitly<Unit>(unit.raw())) {}
  /// @brief Constructor from Unit type(implicit by default, can be made
  /// explicit by TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS macro)
  template <typename AnotherUnit,
            typename std::enable_if<
                std::is_same<T, Unit>::value ||
                    !std::is_same<AnotherUnit, decltype(+std::declval<
                                                        AnotherUnit>())>::value,
                int>::type = 0>
#ifdef TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS
  explicit
#endif
      Prefix(const AnotherUnit &unit)
      : _unit(Internal::convertImplicitly<Unit>(unit) *
              static_cast<T>(Ratio::den) / static_cast<T>(Ratio::num)) {
  }
  /// @brief Explicit constructor from unit with different prefix(implicit by
  /// default, can be made explicit by
  /// TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS macro)
  template <typename AnotherRatio, typename AnotherUnit>
#ifdef TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS
  explicit
#endif
      Prefix(const Prefix<AnotherRatio, AnotherUnit> &unit)
      : _unit(Internal::convertImplicitly<AnotherUnit>(unit.raw()) *
              static_cast<T>(std::ratio_divide<AnotherRatio, Ratio>::num) /
              static_cast<T>(std::ratio_divide<AnotherRatio, Ratio>::den)) {
  }
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
  /// @brief Operator '+'
  template <typename U> Prefix operator+(const U &unit) const {
    return Prefix<Ratio, Unit>(
        +(_unit + Si::Internal::convertImplicitly<Prefix>(unit)._unit));
  }
  /// @brief Operator '+='
  template <typename U> Prefix operator+=(const U &unit) {
    _unit += Si::Internal::convertImplicitly<Prefix>(unit)._unit;
    return *this;
  }
  /// @brief Operator '-'
  template <typename U> Prefix operator-(const U &unit) const {
    return Prefix<Ratio, Unit>(
        +(_unit - Si::Internal::convertImplicitly<Prefix>(unit)._unit));
  }
  /// @brief Operator '-='
  template <typename U> Prefix operator-=(const U &unit) {
    _unit -= Si::Internal::convertImplicitly<Prefix>(unit)._unit;
    return *this;
  }
  /// @brief Operator '*' for units with prefix
  template <typename AnotherRatio, typename AnotherUnit>
  Prefix<std::ratio_multiply<Ratio, AnotherRatio>,
         decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>
  operator*(const Prefix<AnotherRatio, AnotherUnit> &unit) const {
    return Prefix<std::ratio_multiply<Ratio, AnotherRatio>,
                  decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>(
        +(_unit * unit.raw()));
  }
  /// @brief Operator '*' for units without prefix
  template <typename AnotherUnit>
  Prefix<Ratio, decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>
  operator*(const AnotherUnit &unit) const {
    return Prefix<Ratio,
                  decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>(
        +(_unit * unit));
  }
  /// @brief Operator '*=' for container type
  Prefix operator*=(const T &value) {
    _unit *= value;
    return *this;
  }
  /// @brief Operator '/' for units with prefix
  template <typename AnotherRatio, typename AnotherUnit>
  Prefix<std::ratio_divide<Ratio, AnotherRatio>,
         decltype(std::declval<Unit>() / std::declval<AnotherUnit>())>
  operator/(const Prefix<AnotherRatio, AnotherUnit> &unit) const {
    return Prefix<std::ratio_divide<Ratio, AnotherRatio>,
                  decltype(std::declval<Unit>() / std::declval<AnotherUnit>())>(
        +(_unit / unit.raw()));
  }
  /// @brief Operator '/' for units without prefix
  template <typename AnotherUnit>
  Prefix<Ratio, decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>
  operator/(const AnotherUnit &unit) const {
    return Prefix<Ratio,
                  decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>(
        +(_unit / unit));
  }
  /// @brief Operator '/=' for container type
  Prefix operator/=(const T &value) {
    _unit /= value;
    return *this;
  }
};
} // namespace Internal
/// @brief Public interface to apply prefix to unit
/// @tparam Ratio std::ratio representing prefix
/// @tparam Unit Templated class of SI unit
template <typename Ratio, typename Unit>
using Prefix = Internal::Prefix<Ratio, Unit>;
} // namespace Si