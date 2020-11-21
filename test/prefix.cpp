#include "../src/si_internal.hpp"
#include "../src/si_prefix.hpp"
#include <stdexcept>

template<typename T> using u0 = Si::Internal::Unit<T, std::ratio<1>, std::ratio<0>>;
template<typename T> using mu0 = Si::Prefix<std::milli, u0, T>;
template<typename T> using ku0 = Si::Prefix<std::kilo, u0, T>;

template<typename T> using u1 = Si::Internal::Unit<T, std::ratio<0>, std::ratio<1>>;
template<typename T> using mu1 = Si::Prefix<std::milli, u1, T>;
template<typename T> using ku1 = Si::Prefix<std::kilo, u1, T>;

int main() {
    if(!(mu0<int>(1) == mu0<int>(1)))
        throw std::logic_error("Operator '==' failed with same container type");
    if(mu0<int>(1000) == mu0<int>(1))
        throw std::logic_error("Operator '==' failed with same container type(false positive)");
    if(!(mu0<int>(1) == mu0<char>(1)))
        throw std::logic_error("Operator '==' failed with different container type");
    if(mu0<int>(1000) == mu0<long>(1))
        throw std::logic_error("Operator '==' failed with different container type(false positive)");
    if(!(mu0<int>(1000) == u0<int>(1)))
        throw std::logic_error("Operator '==' failed without prefix");
    if(mu0<int>(1000000) == u0<int>(1))
        throw std::logic_error("Operator '==' failed without prefix(false positive)");
    if(!(mu0<long>(1000000) == ku0<int>(1)))
        throw std::logic_error("Operator '==' failed with different prefixes");
    if(mu0<long long>(1000) == ku0<long>(1))
        throw std::logic_error("Operator '==' failed with different prefixes(false positive)");
    if(mu0<int>(1) != mu0<int>(1))
        throw std::logic_error("Operator '!=' failed with same container type(false positive)");
    if(!(mu0<int>(1000) != mu0<int>(1)))
        throw std::logic_error("Operator '!=' failed with same container type");
    if(mu0<int>(1) != mu0<char>(1))
        throw std::logic_error("Operator '!=' failed with different container type(false positive)");
    if(!(mu0<int>(1000) != mu0<long>(1)))
        throw std::logic_error("Operator '!=' failed with different container type");
    if(mu0<int>(1000) != u0<int>(1))
        throw std::logic_error("Operator '!=' failed without prefix(false positive)");
    if(!(mu0<int>(1000000) != u0<int>(1)))
        throw std::logic_error("Operator '!=' failed without prefix");
    if(mu0<long>(1000000) != ku0<int>(1))
        throw std::logic_error("Operator '!=' failed with different prefixes(false positive)");
    if(!(mu0<long long>(1000) != ku0<long>(1)))
        throw std::logic_error("Operator '!=' failed with different prefixes");
    if(!(mu0<float>(10.0) < ku0<double>(0.1)))
        throw std::logic_error("Operator '<' failed");
    if(mu0<float>(100000.0) < ku0<double>(0.01))
        throw std::logic_error("Operator '<' failed(false positive)");
    if(!(mu0<float>(10.0) <= ku0<double>(0.1)))
        throw std::logic_error("Operator '<=' failed");
    if(mu0<float>(100000.0) <= ku0<double>(0.01))
        throw std::logic_error("Operator '<=' failed(false positive)");
    if(!(ku0<float>(1.0) > u0<double>(0.1)))
        throw std::logic_error("Operator '>' failed");
    if(mu0<float>(1.0) > ku0<double>(1.0))
        throw std::logic_error("Operator '>' failed(false positive)");
    if(!(ku0<float>(1.0) >= mu0<double>(100.0)))
        throw std::logic_error("Operator '>=' failed");
    if(mu0<float>(10.0) >= ku0<double>(10.0))
        throw std::logic_error("Operator '>=' failed(false positive)");
}