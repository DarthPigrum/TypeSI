#pragma once
/**
 *  @file   si_derived.hpp
 *  @brief  Derived SI units
 *  @author Mike Zhukov
 ***********************************************/
#include "si_base.hpp"
#include <utility>
namespace Si {
/// @brief Derived SI units
namespace Derived {
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Hertz = decltype(std::declval<Internal::Dimensionless<T>>()/std::declval<Base::Second<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Newton = decltype(std::declval<Base::Kilogram<T>>()*std::declval<Base::Meter<T>>()/(std::declval<Base::Second<T>>()*std::declval<Base::Second<T>>()));
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Pascal = decltype(std::declval<Newton<T>>()/(std::declval<Base::Meter<T>>()* std::declval<Base::Meter<T>>()));
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Joule = decltype(std::declval<Base::Meter<T>>()*std::declval<Newton<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Watt = decltype(std::declval<Joule<T>>()/std::declval<Base::Second<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Coulomb = decltype(std::declval<Base::Second<T>>()*std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Volt = decltype(std::declval<Watt<T>>()/std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Farad = decltype(std::declval<Coulomb<T>>()/std::declval<Volt<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Ohm = decltype(std::declval<Volt<T>>()/std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Siemens = decltype(std::declval<Base::Ampere<T>>()/std::declval<Volt<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Weber = decltype(std::declval<Joule<T>>()/std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Tesla = decltype(std::declval<Newton<T>>()/(std::declval<Base::Ampere<T>>()/std::declval<Base::Meter<T>>()));
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Henry = decltype(std::declval<Weber<T>>()/std::declval<Base::Ampere<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Lumen = Base::Candela<T>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Lux = decltype(std::declval<Lumen<T>>()/(std::declval<Base::Meter<T>>()*std::declval<Base::Meter<T>>()));
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Becquerel = Hertz<T>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Gray = decltype(std::declval<Joule<T>>()/std::declval<Base::Kilogram<T>>());
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Sievert = Gray<T>;
/// @tparam T Any number type such as float, double or long double used as a
/// container
template <typename T> using Katal = decltype(std::declval<Base::Mole<T>>()/std::declval<Base::Second<T>>());
} // namespace Derived
} // namespace Si
