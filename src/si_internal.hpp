#pragma once
/**
 *  @file   si_internal.hpp
 *  @brief  Core logic of units
 *  @author Mike Zhukov
 ***********************************************/
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
template <typename T, int... Powers> class Unit {
  T _value;

public:
  /// @brief Explicit constructor from container type
  explicit Unit(const T &value) : _value(value) {}
  /// @brief Implicit constructor from units with same power values but
  /// different container type
  template <typename AnotherT>
  Unit(const Unit<AnotherT, Powers...> &unit)
      : _value(static_cast<AnotherT>(unit)) {}
  /// @brief Explicit conversion to container type
  explicit operator T() const { return _value; }
  /// @brief Operator '+' for units with same power values
  Unit operator+(const Unit<T, Powers...> &unit) const {
    return Unit(_value + static_cast<T>(unit));
  }
  /// @brief Operator '+=' for units with same power values
  Unit &operator+=(const Unit<T, Powers...> &unit) {
    _value += static_cast<T>(unit);
    return *this;
  }
  /// @brief Operator '-' for units with same power values
  Unit operator-(const Unit<T, Powers...> &unit) const {
    return Unit(_value - static_cast<T>(unit));
  }
  /// @brief Operator '-=' for units with same power values
  Unit &operator-=(const Unit<T, Powers...> &unit) {
    _value -= static_cast<T>(unit);
    return *this;
  }
  /// @brief Operator '*' for dimensionless operand of container type
  Unit operator*(const T &value) const {
    return Unit<T, Powers...>(_value * value);
  }
  /// @brief Operator '/' for dimensionless operand of container type
  Unit operator/(const T &value) const {
    return Unit<T, Powers...>(_value / value);
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
  template <typename AnotherT, int... OtherPowers>
  Unit<T, (Powers + OtherPowers)...>
  operator*(const Unit<AnotherT, OtherPowers...> &unit) const {
    return Unit<T, (Powers + OtherPowers)...>(_value *
                                              static_cast<AnotherT>(unit));
  }
  /// @brief Operator '/' for any unit
  template <typename AnotherT, int... OtherPowers>
  Unit<T, (Powers - OtherPowers)...>
  operator/(const Unit<AnotherT, OtherPowers...> &unit) const {
    return Unit<T, (Powers - OtherPowers)...>(_value /
                                              static_cast<AnotherT>(unit));
  }
};
#endif
/// @brief Dimensionless unit for technical purposes with 7 power values set at
/// 0
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Dimensionless = Unit<T, 0, 0, 0, 0, 0, 0, 0>;
} // namespace Internal
} // namespace Si
