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
template <typename Ratio, typename Unit> class GenericPrefix {
  using T = decltype(+std::declval<Unit>());
  Unit _unit;

public:
  /// @brief Getter for raw Unit reference without prefix applied
  const Unit &raw() const { return _unit; }
  /// @brief Explicit constructor from container type
  explicit GenericPrefix(const T &value) : _unit(value) {}
  /// @brief Implicit constructor from same units with different container type
  template <typename AnotherUnit,
            typename std::enable_if<
                std::is_convertible<AnotherUnit, Unit>::value, int>::type = 0>
  GenericPrefix(const GenericPrefix<Ratio, AnotherUnit> &unit)
      : _unit(Internal::implicit_cast<Unit>(unit.raw())) {}
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
      GenericPrefix(const AnotherUnit &unit)
      : _unit(Internal::implicit_cast<Unit>(unit) * static_cast<T>(Ratio::den) /
              static_cast<T>(Ratio::num)) {
  }
  /// @brief Explicit constructor from unit with different prefix(implicit by
  /// default, can be made explicit by
  /// TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS macro)
  template <typename AnotherRatio, typename AnotherUnit>
#ifdef TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS
  explicit
#endif
      GenericPrefix(const GenericPrefix<AnotherRatio, AnotherUnit> &unit)
      : _unit(Internal::implicit_cast<AnotherUnit>(unit.raw()) *
              static_cast<T>(std::ratio_divide<AnotherRatio, Ratio>::num) /
              static_cast<T>(std::ratio_divide<AnotherRatio, Ratio>::den)) {
  }
  /// @brief Conversion to container type via unary '+'
  T operator+() const { return +_unit; }
  /// @brief Operator '=='
  template <typename U>
  decltype(std::declval<Unit>() == std::declval<Unit>())
  operator==(const U &unit) const {
    return _unit == Si::Internal::implicit_cast<GenericPrefix>(unit)._unit;
  }
  /// @brief Operator '!='
  template <typename U>
  decltype(std::declval<Unit>() != std::declval<Unit>())
  operator!=(const U &unit) const {
    return _unit != Si::Internal::implicit_cast<GenericPrefix>(unit)._unit;
  }
  /// @brief Operator '<'
  template <typename U>
  decltype(std::declval<Unit>() < std::declval<Unit>())
  operator<(const U &unit) const {
    return _unit < Si::Internal::implicit_cast<GenericPrefix>(unit)._unit;
  }
  /// @brief Operator '<='
  template <typename U>
  decltype(std::declval<Unit>() <= std::declval<Unit>())
  operator<=(const U &unit) const {
    return _unit <= Si::Internal::implicit_cast<GenericPrefix>(unit)._unit;
  }
  /// @brief Operator '>'
  template <typename U>
  decltype(std::declval<Unit>() > std::declval<Unit>())
  operator>(const U &unit) const {
    return _unit > Si::Internal::implicit_cast<GenericPrefix>(unit)._unit;
  }
  /// @brief Operator '>='
  template <typename U>
  decltype(std::declval<Unit>() >= std::declval<Unit>())
  operator>=(const U &unit) const {
    return _unit >= Si::Internal::implicit_cast<GenericPrefix>(unit)._unit;
  }
  /// @brief Operator '+'
  template <typename U> GenericPrefix operator+(const U &unit) const {
    return GenericPrefix<Ratio, Unit>(
        +(_unit + Si::Internal::implicit_cast<GenericPrefix>(unit)._unit));
  }
  /// @brief Operator '+='
  template <typename U> GenericPrefix operator+=(const U &unit) {
    _unit += Si::Internal::implicit_cast<GenericPrefix>(unit)._unit;
    return *this;
  }
  /// @brief Operator '-'
  template <typename U> GenericPrefix operator-(const U &unit) const {
    return GenericPrefix<Ratio, Unit>(
        +(_unit - Si::Internal::implicit_cast<GenericPrefix>(unit)._unit));
  }
  /// @brief Operator '-='
  template <typename U> GenericPrefix operator-=(const U &unit) {
    _unit -= Si::Internal::implicit_cast<GenericPrefix>(unit)._unit;
    return *this;
  }
  /// @brief Operator '*' for units with prefix
  template <typename AnotherRatio, typename AnotherUnit>
  GenericPrefix<std::ratio_multiply<Ratio, AnotherRatio>,
                decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>
  operator*(const GenericPrefix<AnotherRatio, AnotherUnit> &unit) const {
    return GenericPrefix<std::ratio_multiply<Ratio, AnotherRatio>,
                         decltype(std::declval<Unit>() *
                                  std::declval<AnotherUnit>())>(
        +(_unit * unit.raw()));
  }
  /// @brief Operator '*' for units without prefix
  template <typename AnotherUnit>
  GenericPrefix<Ratio,
                decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>
  operator*(const AnotherUnit &unit) const {
    return GenericPrefix<Ratio, decltype(std::declval<Unit>() *
                                         std::declval<AnotherUnit>())>(
        +(_unit * unit));
  }
  /// @brief Operator '*=' for container type
  GenericPrefix operator*=(const T &value) {
    _unit *= value;
    return *this;
  }
  /// @brief Operator '/' for units with prefix
  template <typename AnotherRatio, typename AnotherUnit>
  GenericPrefix<std::ratio_divide<Ratio, AnotherRatio>,
                decltype(std::declval<Unit>() / std::declval<AnotherUnit>())>
  operator/(const GenericPrefix<AnotherRatio, AnotherUnit> &unit) const {
    return GenericPrefix<std::ratio_divide<Ratio, AnotherRatio>,
                         decltype(std::declval<Unit>() /
                                  std::declval<AnotherUnit>())>(
        +(_unit / unit.raw()));
  }
  /// @brief Operator '/' for units without prefix
  template <typename AnotherUnit>
  GenericPrefix<Ratio,
                decltype(std::declval<Unit>() * std::declval<AnotherUnit>())>
  operator/(const AnotherUnit &unit) const {
    return GenericPrefix<Ratio, decltype(std::declval<Unit>() *
                                         std::declval<AnotherUnit>())>(
        +(_unit / unit));
  }
  /// @brief Operator '/=' for container type
  GenericPrefix operator/=(const T &value) {
    _unit /= value;
    return *this;
  }
};
template <typename Ratio, typename Unit,
          typename T = decltype(+std::declval<Unit>())>
GenericPrefix<Ratio, Unit> applyPrefix();
template <
    typename Ratio, typename Unit,
    typename T = decltype(+std::declval<typename Unit::template type<Ratio>>())>
typename Unit::template type<Ratio> applyPrefix();
} // namespace Internal
/// @brief Public interface to apply prefix to unit
/// @tparam Ratio std::ratio representing prefix
/// @tparam Unit Template class of SI unit
template <typename Ratio, typename Unit>
using Prefix = decltype(Internal::applyPrefix<Ratio, Unit>());
} // namespace Si