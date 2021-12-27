#pragma once
#include "../../src/si_internal.hpp"

template <typename T>
using ab = Si::Internal::Unit<T, std::ratio<0>, std::ratio<0>>;

template <typename T>
using Ab = Si::Internal::Unit<T, std::ratio<0>, std::ratio<1>>;
template <typename T>
using aB = Si::Internal::Unit<T, std::ratio<1>, std::ratio<0>>;
template <typename T>
using AB = Si::Internal::Unit<T, std::ratio<1>, std::ratio<1>>;

template <typename T>
using Ab_ = Si::Internal::Unit<T, std::ratio<0>, std::ratio<-1>>;
template <typename T>
using aB_ = Si::Internal::Unit<T, std::ratio<-1>, std::ratio<0>>;
template <typename T>
using AB_ = Si::Internal::Unit<T, std::ratio<-1>, std::ratio<-1>>;