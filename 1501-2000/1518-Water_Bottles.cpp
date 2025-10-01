#include <iostream>

int numWaterBottles(int numBottles, int numExchange) {
  int fullBottles = numBottles;
  int emptyBottles = 0;
  int res = 0;

  while (fullBottles > 0 || emptyBottles > numExchange) {
    res += fullBottles;
    emptyBottles += fullBottles;
    fullBottles = static_cast<int>(emptyBottles / numExchange);
    emptyBottles = emptyBottles % numExchange;
  }

  return res;
}

int main() {
  return 0;
}