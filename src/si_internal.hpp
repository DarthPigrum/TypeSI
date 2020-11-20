#pragma once
/**
 *  @file   si_internal.hpp
 *  @brief  Core logic of units
 *  @author Mike Zhukov
 ***********************************************/
#include <ratio>
#include <utility>
namespace Si {
/// @brief Technical namespace for core library logic
namespace Internal {
#ifdef TYPE_SI_DISABLE_CHECKS
/// @brief If TYPE_SI_DISABLE_CHECKS flag is set all units are defined as their
/// container type
/// @tparam T Any number type such as float, double or long double used as a
/// container
/// @tparam Powers Ignored here
template <typename T, int... Powers> using Unit = T;
#else
/// @brief Generic unit type
/// @tparam T Any number type such as float, double or long double used as a
/// container
/// @tparam Powers Integers representing powers of base units in SI
template <typename T, typename... Powers> class Unit {
  T _value;

public:
  /// @brief Explicit constructor from container type
  explicit Unit(const T &value = T()) : _value(value) {}
  /// @brief Implicit constructor from units with same power values but
  /// different container type
  template <typename AnotherT>
  Unit(const Unit<AnotherT, Powers...> &unit)
      : _value(static_cast<AnotherT>(unit)) {}
  /// @brief Explicit conversion to any type compatible with container(including
  /// other units)
  template <typename AnotherT> explicit operator AnotherT() const {
    return static_cast<AnotherT>(_value);
  }
  /// @brief Conversion to container type via unary '+'
  T operator+() const { return _value; }
  /// @brief Operator '==' for units with same power values
  template <typename AnotherT>
  decltype(std::declval<T>() == std::declval<AnotherT>())
  operator==(const Unit<AnotherT, Powers...> &unit) const {
    return _value == static_cast<AnotherT>(unit);
  }
  /// @brief Operator '!=' for units with same power values
  template <typename AnotherT>
  decltype(std::declval<T>() != std::declval<AnotherT>())
  operator!=(const Unit<AnotherT, Powers...> &unit) const {
    return _value != static_cast<AnotherT>(unit);
  }
  /// @brief Operator '<' for units with same power values
  template <typename AnotherT>
  decltype(std::declval<T>() < std::declval<AnotherT>())
  operator<(const Unit<AnotherT, Powers...> &unit) const {
    return _value < static_cast<AnotherT>(unit);
  }
  /// @brief Operator '<=' for units with same power values
  template <typename AnotherT>
  decltype(std::declval<T>() <= std::declval<AnotherT>())
  operator<=(const Unit<AnotherT, Powers...> &unit) const {
    return _value <= static_cast<AnotherT>(unit);
  }
  /// @brief Operator '>' for units with same power values
  template <typename AnotherT>
  decltype(std::declval<T>() > std::declval<AnotherT>())
  operator>(const Unit<AnotherT, Powers...> &unit) const {
    return _value > static_cast<AnotherT>(unit);
  }
  /// @brief Operator '>=' for units with same power values
  template <typename AnotherT>
  decltype(std::declval<T>() >= std::declval<AnotherT>())
  operator>=(const Unit<AnotherT, Powers...> &unit) const {
    return _value >= static_cast<AnotherT>(unit);
  }
  /// @brief Operator '+' for units with same power values
  template <typename AnotherT>
  Unit<decltype(std::declval<T>() + std::declval<AnotherT>()), Powers...>
  operator+(const Unit<AnotherT, Powers...> &unit) const {
    return Unit<decltype(std::declval<T>() - std::declval<AnotherT>()),
                Powers...>(_value + static_cast<AnotherT>(unit));
  }
  /// @brief Prefix increment
  Unit &operator++() {
    ++_value;
    return *this;
  }
  /// @brief Postfix increment
  Unit operator++(int) { return Unit(_value++); }
  /// @brief Operator '+=' for units with same power values
  template <typename AnotherT>
  Unit &operator+=(const Unit<AnotherT, Powers...> &unit) {
    _value += static_cast<AnotherT>(unit);
    return *this;
  }
  /// @brief Operator '-' for units with same power values
  template <typename AnotherT>
  Unit<decltype(std::declval<T>() - std::declval<AnotherT>()), Powers...>
  operator-(const Unit<AnotherT, Powers...> &unit) const {
    return Unit<decltype(std::declval<T>() - std::declval<AnotherT>()),
                Powers...>(_value - static_cast<AnotherT>(unit));
  }
  /// @brief Operator '-=' for units with same power values
  template <typename AnotherT>
  Unit &operator-=(const Unit<AnotherT, Powers...> &unit) {
    _value -= static_cast<AnotherT>(unit);
    return *this;
  }
  /// @brief Prefix decrement
  Unit &operator--() {
    --_value;
    return *this;
  }
  /// @brief Postfix decrement
  Unit operator--(int) { return Unit(_value--); }
  /// @brief Operator '*' for dimensionless operand of container type
  Unit<decltype(std::declval<T>() * std::declval<T>()), Powers...>
  operator*(const T &value) const {
    return Unit<decltype(std::declval<T>() * std::declval<T>()), Powers...>(
        _value * value);
  }
  /// @brief Operator '/' for dimensionless operand of container type
  Unit<decltype(std::declval<T>() / std::declval<T>()), Powers...>
  operator/(const T &value) const {
    return Unit<decltype(std::declval<T>() / std::declval<T>()), Powers...>(
        _value / value);
  }
  /// @brief Operator '*=' for dimensionless operand of container type
  Unit &operator*=(const T &value) {
    _value *= value;
    return *this;
  }
  /// @brief Operator '/=' for dimensionless operand of container type
  Unit &operator/=(const T &value) {
    _value /= value;
    return *this;
  }
  /// @brief Operator '*' for any unit
  template <typename AnotherT, typename... OtherPowers>
  Unit<decltype(std::declval<T>() * std::declval<AnotherT>()),
       std::ratio_add<Powers, OtherPowers>...>
  operator*(const Unit<AnotherT, OtherPowers...> &unit) const {
    return Unit<decltype(std::declval<T>() * std::declval<AnotherT>()),
                std::ratio_add<Powers, OtherPowers>...>(
        _value * static_cast<AnotherT>(unit));
  }
  /// @brief Operator '/' for any unit
  template <typename AnotherT, typename... OtherPowers>
  Unit<decltype(std::declval<T>() / std::declval<AnotherT>()),
       std::ratio_subtract<Powers, OtherPowers>...>
  operator/(const Unit<AnotherT, OtherPowers...> &unit) const {
    return Unit<decltype(std::declval<T>() / std::declval<AnotherT>()),
                std::ratio_subtract<Powers, OtherPowers>...>(
        _value / static_cast<AnotherT>(unit));
  }
};
#endif
/// @brief Dimensionless unit for technical purposes with 7 power values set at
/// 0
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T>
using Dimensionless =
    Unit<T, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>,
         std::ratio<0>, std::ratio<0>, std::ratio<0>>;
} // namespace Internal
} // namespace Si
