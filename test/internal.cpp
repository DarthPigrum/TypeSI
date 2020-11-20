#include "../src/si_internal.hpp"
#include <stdexcept>

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

int main() {
  if (typeid(ab<float>).hash_code() != typeid(ab<float>).hash_code())
    throw std::logic_error(
        "Template class Unit yields different results with same container");
  if (typeid(ab<float>).hash_code() == typeid(ab<double>).hash_code())
    throw std::logic_error(
        "Template class Unit is indifferent to container type");
  if (typeid(decltype(std::declval<Ab<float>>() + std::declval<Ab<float>>()))
          .hash_code() != typeid(Ab<float>).hash_code())
    throw std::logic_error(
        "Template class Unit: operator '+' failed with same type operands");
  if (typeid(decltype(std::declval<aB<float>>() - std::declval<aB<float>>()))
          .hash_code() != typeid(aB<float>).hash_code())
    throw std::logic_error(
        "Template class Unit: operator '-' failed with same type operands");
  if (typeid(decltype(std::declval<Ab_<float>>() += std::declval<Ab_<float>>()))
          .hash_code() != typeid(Ab_<float>).hash_code())
    throw std::logic_error(
        "Template class Unit: operator '+=' failed with same type operands");
  if (typeid(decltype(std::declval<aB_<float>>() -= std::declval<aB_<float>>()))
          .hash_code() != typeid(aB_<float>).hash_code())
    throw std::logic_error(
        "Template class Unit: operator '-=' failed with same type operands");
  if (typeid(decltype(std::declval<Ab<float>>() * std::declval<Ab_<float>>()))
          .hash_code() != typeid(ab<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '*' failed");
  if (typeid(decltype(std::declval<AB<float>>() / std::declval<aB<float>>()))
          .hash_code() != typeid(Ab<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '/' failed");
  if (typeid(decltype(std::declval<Ab<float>>() *= std::declval<float>()))
          .hash_code() != typeid(Ab<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '*=' failed with "
                           "second operand of container type");
  if (typeid(decltype(std::declval<aB<float>>() /= std::declval<float>()))
          .hash_code() != typeid(aB<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '/=' failed with "
                           "second operand of container type");
  if (typeid(decltype(std::declval<AB<double>>() * std::declval<AB_<float>>()))
          .hash_code() != typeid(ab<double>).hash_code())
    throw std::logic_error(
        "Template class Unit: implicit container type conversion failed");
  if (typeid(decltype(+std::declval<ab<double>>())).hash_code() !=
      typeid(double).hash_code())
    throw std::logic_error("Unary plus conversion failed");
  if (!(ab<int>(1) == ab<int>(1)))
    throw std::logic_error("Operator '==' failed");
  if (!(Ab<float>(1.0) != Ab<float>(1.5)))
    throw std::logic_error("Operator '!=' failed");
  if (!(aB<float>(1.0) <= aB<double>(1.5)))
    throw std::logic_error("Operator '<=' failed with different values");
  if (!(AB<int>(1) <= AB<int>(1)))
    throw std::logic_error("Operator '<=' failed with equal values");
  if (!(ab<float>(1.0) < ab<double>(1.5)))
    throw std::logic_error("Operator '<' failed");
  if (!(Ab<double>(2.0) >= Ab<double>(1.5)))
    throw std::logic_error("Operator '>=' failed with different values");
  if (!(aB<int>(2) >= aB<int>(2)))
    throw std::logic_error("Operator '>=' failed with equal values");
  if (!(AB<float>(2.0) > AB<float>(1.5)))
    throw std::logic_error("Operator '>' failed");
  if (ab<long long>(1) + ab<int>(2) != ab<char>(3))
    throw std::logic_error("Operator '+' failed");
  if ((Ab<long long>(1) += Ab<int>(2)) != Ab<char>(3))
    throw std::logic_error("Operator '+=' failed");
  if (aB<int>(1) - aB<char>(2) != aB<long long>(-1))
    throw std::logic_error("Operator '-' failed");
  if ((AB<long long>(1) -= AB<int>(2)) != AB<char>(-1))
    throw std::logic_error("Operator '-=' failed");
  if (Ab<unsigned long long>(1) * aB<unsigned>(2) != AB<unsigned char>(2))
    throw std::logic_error("Operator '*' failed with another unit type");
  if (aB<long>(1) * 3 != aB<int>(3))
    throw std::logic_error("Operator '*' failed with container type");
  if ((AB<unsigned long long>(2) *= 5) != AB<char>(10))
    throw std::logic_error("Operator '*=' failed");
  if (ab<int>(6) / AB<long>(2) != AB_<char>(3))
    throw std::logic_error("Operator '/' failed with another unit type");
  if (Ab_<long long>(6) / 3 != Ab_<unsigned char>(2))
    throw std::logic_error("Operator '/' failed with container type");
  if ((aB<unsigned long long>(12) /= 3) != aB<unsigned>(4))
    throw std::logic_error("Operator '/=' failed");
}