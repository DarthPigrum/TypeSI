#pragma once
namespace Si {
namespace Internal {
#ifdef TYPE_SI_DISABLE_CHECKS
template <typename T, int... Powers> using Unit = T;
#else
template <typename T, int... Powers> class Unit {
  T _value;

public:
  explicit Unit(const T &value) : _value(value) {}
  template <typename AnotherT>
  Unit(const Unit<AnotherT, Powers...> &unit)
      : _value(static_cast<AnotherT>(unit)) {}
  explicit operator T() const { return _value; }
  Unit operator+(const Unit<T, Powers...> &unit) const {
    return Unit(_value + static_cast<T>(unit));
  }
  Unit &operator+=(const Unit<T, Powers...> &unit) {
    _value += static_cast<T>(unit);
    return *this;
  }
  Unit operator-(const Unit<T, Powers...> &unit) const {
    return Unit(_value - static_cast<T>(unit));
  }
  Unit &operator-=(const Unit<T, Powers...> &unit) {
    _value -= static_cast<T>(unit);
    return *this;
  }
  Unit operator*(const T &value) const {
    return Unit<T, Powers...>(_value * value);
  }
  Unit operator/(const T &value) const {
    return Unit<T, Powers...>(_value / value);
  }
  Unit &operator*=(const T &value) {
    _value *= value;
    return *this;
  }
  Unit &operator/=(const T &value) {
    _value /= value;
    return *this;
  }
  template <typename AnotherT, int... OtherPowers>
  Unit<T, (Powers + OtherPowers)...>
  operator*(const Unit<AnotherT, OtherPowers...> &unit) const {
    return Unit<T, (Powers + OtherPowers)...>(_value *
                                              static_cast<AnotherT>(unit));
  }
  template <typename AnotherT, int... OtherPowers>
  Unit<T, (Powers - OtherPowers)...>
  operator/(const Unit<AnotherT, OtherPowers...> &unit) const {
    return Unit<T, (Powers - OtherPowers)...>(_value /
                                              static_cast<AnotherT>(unit));
  }
};
#endif
template <typename T> using Dimensionless = Unit<T, 0, 0, 0, 0, 0, 0, 0>;
} // namespace Internal
} // namespace Si
