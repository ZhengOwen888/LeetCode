// 3100. Water Bottles II
#include <iostream>

int maxBottlesDrunk(int numBottles, int numExchange) {
  int fullBottles = numBottles;
  int emptyBottles = 0;
  int exchange = numExchange;
  int res = 0;

  while (fullBottles > 0 || (emptyBottles > 0 && emptyBottles >= exchange)) {

    while (exchange <= emptyBottles) {
      fullBottles += 1;
      emptyBottles -= exchange;
      exchange++;
    }

    res += fullBottles;
    emptyBottles += fullBottles;
    fullBottles = 0;
  }

  return res;
}