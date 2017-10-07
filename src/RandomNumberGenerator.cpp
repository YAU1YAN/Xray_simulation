#include "RandomNumberGenerator.hpp"

#include <iostream>

float RandomNumberGenerator::rng() {
  int q = INT_MAX / a;
  int r = INT_MAX % a;
  int k = currentSeed / q;
  int result = a * (currentSeed - k * q) - k * r;
  if (result < 0) {
    result = result + INT_MAX;
  }
  currentSeed = result; 
  return (float)result / (float)INT_MAX;
}

float RandomNumberGenerator::random() {
  return rng();
}

void RandomNumberGenerator::seed(int newSeed) {
  currentSeed = newSeed;
}