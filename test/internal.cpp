#include <stdexcept>
#include "../src/si_internal.hpp"

template<typename T> using ab = Si::Internal::Unit<T, 0, 0>;

template<typename T> using Ab = Si::Internal::Unit<T, 0, 1>;
template<typename T> using aB = Si::Internal::Unit<T, 1, 0>;
template<typename T> using AB = Si::Internal::Unit<T, 1, 1>;

template<typename T> using _Ab = Si::Internal::Unit<T, 0, -1>;
template<typename T> using _aB = Si::Internal::Unit<T, -1, 0>;
template<typename T> using _AB = Si::Internal::Unit<T, -1, -1>;

int main(){
  if(typeid(ab<float>).hash_code() != typeid(ab<float>).hash_code())
    throw std::logic_error("Template class Unit yields different results with same container");
  if(typeid(ab<float>).hash_code() == typeid(ab<double>).hash_code())
    throw std::logic_error("Template class Unit is indifferent to container type");
  if(typeid(decltype(std::declval<Ab<float>>()+std::declval<Ab<float>>())).hash_code() != typeid(Ab<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '+' failed with same type operands");
  if(typeid(decltype(std::declval<aB<float>>()-std::declval<aB<float>>())).hash_code() != typeid(aB<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '-' failed with same type operands");
  if(typeid(decltype(std::declval<_Ab<float>>()+=std::declval<_Ab<float>>())).hash_code() != typeid(_Ab<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '+=' failed with same type operands");
  if(typeid(decltype(std::declval<_aB<float>>()-=std::declval<_aB<float>>())).hash_code() != typeid(_aB<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '-=' failed with same type operands");
  if(typeid(decltype(std::declval<Ab<float>>()*std::declval<_Ab<float>>())).hash_code() != typeid(ab<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '*' failed");
  if(typeid(decltype(std::declval<AB<float>>()/std::declval<aB<float>>())).hash_code() != typeid(Ab<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '/' failed");
  if(typeid(decltype(std::declval<Ab<float>>()*=std::declval<float>())).hash_code() != typeid(Ab<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '*=' failed with second operand of container type");
  if(typeid(decltype(std::declval<aB<float>>()/=std::declval<float>())).hash_code() != typeid(aB<float>).hash_code())
    throw std::logic_error("Template class Unit: operator '/=' failed with second operand of container type");
  if(typeid(decltype(std::declval<AB<double>>()*std::declval<_AB<float>>())).hash_code() != typeid(ab<double>).hash_code())
    throw std::logic_error("Template class Unit: implicit container type conversion failed");
  if(typeid(decltype(std::declval<AB<double>>()*std::declval<_AB<float>>())).hash_code() == typeid(ab<float>).hash_code())
    throw std::logic_error("Template class Unit: implicit container type conversion choice is unintended");
}