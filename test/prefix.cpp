#include "../src/si_internal.hpp"
#include "../src/si_prefix.hpp"
#include <stdexcept>

template <typename T>
using u0 = Si::Internal::Unit<T, std::ratio<0>, std::ratio<0>>;
template <typename T> using mu0 = Si::Prefix<std::milli, u0<T>>;
template <typename T> using ku0 = Si::Prefix<std::kilo, u0<T>>;

template <typename T>
using u1 = Si::Internal::Unit<T, std::ratio<1>, std::ratio<0>>;
template <typename T> using mu1 = Si::Prefix<std::milli, u1<T>>;
template <typename T> using ku1 = Si::Prefix<std::kilo, u1<T>>;

template <typename T>
using u2 = Si::Internal::Unit<T, std::ratio<0>, std::ratio<1>>;
template <typename T> using mu2 = Si::Prefix<std::milli, u2<T>>;
template <typename T> using ku2 = Si::Prefix<std::kilo, u2<T>>;

template <typename T>
using u3 = Si::Internal::Unit<T, std::ratio<1>, std::ratio<1>>;
template <typename T> using mu3 = Si::Prefix<std::milli, u3<T>>;
template <typename T> using ku3 = Si::Prefix<std::kilo, u3<T>>;

int main() {
  if (!(mu1<int>(1) == mu1<int>(1)))
    throw std::logic_error("Operator '==' failed with same container type");
  if (mu1<int>(1000) == mu1<int>(1))
    throw std::logic_error(
        "Operator '==' failed with same container type(false positive)");
  if (!(mu1<int>(1) == mu1<char>(1)))
    throw std::logic_error(
        "Operator '==' failed with different container type");
  if (mu1<int>(1000) == mu1<long>(1))
    throw std::logic_error(
        "Operator '==' failed with different container type(false positive)");
  if (!(mu1<int>(1000) == u1<int>(1)))
    throw std::logic_error("Operator '==' failed without prefix");
  if (mu1<int>(1000000) == u1<int>(1))
    throw std::logic_error(
        "Operator '==' failed without prefix(false positive)");
  if (!(mu1<long>(1000000) == ku1<int>(1)))
    throw std::logic_error("Operator '==' failed with different prefixes");
  if (mu1<long long>(1000) == ku1<long>(1))
    throw std::logic_error(
        "Operator '==' failed with different prefixes(false positive)");
  if (mu1<int>(1) != mu1<int>(1))
    throw std::logic_error(
        "Operator '!=' failed with same container type(false positive)");
  if (!(mu1<int>(1000) != mu1<int>(1)))
    throw std::logic_error("Operator '!=' failed with same container type");
  if (mu1<int>(1) != mu1<char>(1))
    throw std::logic_error(
        "Operator '!=' failed with different container type(false positive)");
  if (!(mu1<int>(1000) != mu1<long>(1)))
    throw std::logic_error(
        "Operator '!=' failed with different container type");
  if (mu1<int>(1000) != u1<int>(1))
    throw std::logic_error(
        "Operator '!=' failed without prefix(false positive)");
  if (!(mu1<int>(1000000) != u1<int>(1)))
    throw std::logic_error("Operator '!=' failed without prefix");
  if (mu1<long>(1000000) != ku1<int>(1))
    throw std::logic_error(
        "Operator '!=' failed with different prefixes(false positive)");
  if (!(mu1<long long>(1000) != ku1<long>(1)))
    throw std::logic_error("Operator '!=' failed with different prefixes");
  if (!(mu1<float>(10.0) < ku1<double>(0.1)))
    throw std::logic_error("Operator '<' failed");
  if (mu1<float>(100000.0) < ku1<double>(0.01))
    throw std::logic_error("Operator '<' failed(false positive)");
  if (!(mu1<float>(10.0) <= ku1<double>(0.1)))
    throw std::logic_error("Operator '<=' failed");
  if (mu1<float>(100000.0) <= ku1<double>(0.01))
    throw std::logic_error("Operator '<=' failed(false positive)");
  if (!(ku1<float>(1.0) > u1<double>(0.1)))
    throw std::logic_error("Operator '>' failed");
  if (mu1<float>(1.0) > ku1<double>(1.0))
    throw std::logic_error("Operator '>' failed(false positive)");
  if (!(ku1<float>(1.0) >= mu1<double>(100.0)))
    throw std::logic_error("Operator '>=' failed");
  if (mu1<float>(10.0) >= ku1<double>(10.0))
    throw std::logic_error("Operator '>=' failed(false positive)");
  if (mu1<int>(100) + ku1<long>(1) != mu1<long long>(1000100))
    throw std::logic_error("Operator '+' failed");
  if ((mu1<int>(100) += ku1<long>(1)) != mu1<long long>(1000100))
    throw std::logic_error("Operator '+=' failed");
  if (mu1<long>(1100) - u1<int>(1) != mu1<long long>(100))
    throw std::logic_error("Operator '-' failed");
  if ((mu1<long>(1100) -= u1<int>(1)) != mu1<long long>(100))
    throw std::logic_error("Operator '-=' failed");
  if (mu1<int>(10) * ku2<long>(1) != u3<long long>(10))
    throw std::logic_error(
        "Operator '*' failed with both operands prefixed units");
  if (mu1<int>(100) * u2<long>(1) != mu1<long long>(100))
    throw std::logic_error("Operator '*' failed with non-prefixed operand");
  if ((mu1<int>(10) *= 10) != mu1<long long>(100))
    throw std::logic_error("Operator '*=' failed");
  if (ku1<int>(10) / ku1<long>(1) != u0<long long>(10))
    throw std::logic_error(
        "Operator '/' failed with both operands prefixed units");
  if (mu2<int>(100) / u2<long>(1) != mu1<long long>(100))
    throw std::logic_error("Operator '/' failed with non-prefixed operand");
  if ((mu2<int>(100) /= 10) != mu2<long long>(10))
    throw std::logic_error("Operator '/=' failed");
}