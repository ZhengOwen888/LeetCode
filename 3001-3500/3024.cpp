// 3024. Types of Triangle

#include <string>
#include <vector>

using namespace std;

string triangleType(vector<int>& nums) {
  int sideA = nums[0];
  int sideB = nums[1];
  int sideC = nums[2];

  if (
    sideA + sideB < sideC ||
    sideB + sideC < sideA ||
    sideC + sideA < sideB
  ) {
    return "Not a triangle";

  } else if (
    sideA == sideB && sideB == sideC
  ) {
    return "equilateral";

  } else if (
    sideA == sideB ||
    sideB == sideC ||
    sideC == sideA
  ) {
    return "isosceles";

  } else {
    return "scalene";
  }
}