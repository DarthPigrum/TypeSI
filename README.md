## TypeSI - Units of "Système international" Blended for C++
Header-only C++ library that provides type safety for handling physical values defined in the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units) regulated by the [International Bureau of Weights and Measures (BIPM)](https://www.bipm.org/en/about-us/)  and published in the [SI brochure](https://www.bipm.org/en/publications/si-brochure/).
Example:
```cpp
#include "src/si_base.hpp"
#include "src/si_derived.hpp"
#include <iostream>

Si::Derived::Watt<double> calculatePower(Si::Derived::Joule<double> energy,
                                         Si::Base::Second<double> time) {
  return energy / time;
}

int main() {
  using namespace Si::Base::Literals;
  Si::Base::Second<double> time(1.5);
  auto speed = 29.4_m / time;
  auto acceleration = speed / 2.0_s;
  auto power = calculatePower(acceleration * 1.2_kg * 0.4_m, 3.2_s);
  std::cout << "With g = " << +acceleration << " power equals " << +power
            << std::endl;
}
```
If any of the explicitly specified types doesn't match with compile-time calculated one the program will just fail to compile.
```cpp
auto power = calculatePower(acceleration * 1.2_kg, 3.2_s); // won't compile
```
You can also add prefixes to units at will. They will be checked and automatically converted on demand.
```cpp
#include "src/si_base.hpp"
#include "src/si_derived.hpp"
#include "src/si_prefix.hpp"
#include <iostream>

template <typename T>
using minute = Si::Prefix<std::ratio<60>, Si::Base::Second<T>>;
template <typename T>
using kWth = Si::Prefix<std::ratio<3600000>, Si::Derived::Joule<T>>;

Si::Prefix<std::giga, Si::Derived::Watt<double>>
calculatePower(kWth<double> energy, minute<double> time) {
  return energy / time;
}

int main() {
  auto energy = kWth<double>(100833);
  auto time = minute<double>(5);
  std::cout << "If you've spent " << +energy << " kilowatt*hours in " << +time
            << " minutes your grid allows to draw "
            << +calculatePower(energy, time) << " gigawatts of power"
            << std::endl;
}
```
On top of that you are provided with compatible pow function
```cpp
#include "src/si_base.hpp"
#include "src/si_derived.hpp"
#include "src/si_math.hpp"
#include <iostream>

void printPressure(Si::Prefix<std::kilo, Si::Derived::Pascal<double>> p) {
  std::cout << "Pressure is " << +p << " kPa" << std::endl;
}

int main() {
  using namespace Si::Base::Literals;
  using namespace Si::Derived::Literals;
  printPressure(1000.0_N / Si::Math::pow<std::ratio<2>>(0.1_m));
}
```
