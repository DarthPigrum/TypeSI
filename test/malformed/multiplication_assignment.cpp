#include "common.hpp"
int main() {
  AB<float> x(0.5);
  x *= AB<double>(1.5);
}