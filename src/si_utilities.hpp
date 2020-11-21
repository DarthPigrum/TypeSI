#pragma once
/// @file   si_utilities.hpp
/// @brief  Internal instruments of the library, that does not involve core
/// logic
namespace Si {
namespace Internal {
template <typename T> const T &convertImplicitly(const T &t) { return t; }
} // namespace Internal
} // namespace Si