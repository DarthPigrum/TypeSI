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
template <typename Ratio, template <typename> class Unit, typename T>
class Prefix {
  Unit<T> _unit;
  static const Prefix &_convert(const Prefix &unit) { return unit; }

public:
  /// @brief Explicit constructor from container type
  explicit Prefix(const T &value) : _unit(value){};
  /// @brief Implicit constructor from same units with different container type
  template <typename AnotherT>
  Prefix(const Prefix<Ratio, Unit, AnotherT> &unit) : _unit(+unit){};
  /// @brief Constructor from Unit type(implicit by default, can be made
  /// explicit by TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS macro)
  template <typename AnotherT>
#ifdef TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS
  explicit
#endif
      Prefix(const Unit<AnotherT> &unit)
      : _unit(+unit * static_cast<AnotherT>(Ratio::den) /
              static_cast<AnotherT>(Ratio::num)){};
  /// @brief Explicit constructor from unit with different prefix(implicit by
  /// default, can be made explicit by
  /// TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS macro)
  template <typename AnotherT, typename AnotherRatio>
#ifdef TYPE_SI_DISALLOW_IMPLICIT_PREFIX_CONVERSIONS
  explicit
#endif
      Prefix(const Prefix<AnotherRatio, Unit, AnotherT> &unit)
      : _unit(
            +unit *
            static_cast<AnotherT>(std::ratio_divide<AnotherRatio, Ratio>::num) /
            static_cast<AnotherT>(
                std::ratio_divide<AnotherRatio, Ratio>::den)){};
  /// @brief Conversion to container type via unary '+'
  T operator+() const { return +_unit; }
  /// @brief Operator '=='
  template <typename U>
  decltype(std::declval<Unit<T>>() == std::declval<Unit<T>>())
  operator==(const U &unit) const {
    return _unit == Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '!='
  template <typename U>
  decltype(std::declval<Unit<T>>() != std::declval<Unit<T>>())
  operator!=(const U &unit) const {
    return _unit != Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '<'
  template <typename U>
  decltype(std::declval<Unit<T>>() < std::declval<Unit<T>>())
  operator<(const U &unit) const {
    return _unit < Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '<='
  template <typename U>
  decltype(std::declval<Unit<T>>() <= std::declval<Unit<T>>())
  operator<=(const U &unit) const {
    return _unit <= Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '>'
  template <typename U>
  decltype(std::declval<Unit<T>>() > std::declval<Unit<T>>())
  operator>(const U &unit) const {
    return _unit > Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
  /// @brief Operator '>='
  template <typename U>
  decltype(std::declval<Unit<T>>() >= std::declval<Unit<T>>())
  operator>=(const U &unit) const {
    return _unit >= Si::Internal::convertImplicitly<Prefix>(unit)._unit;
  }
};
} // namespace Si