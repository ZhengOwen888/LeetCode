//167. Two Sum II - Input Array Is Sorted

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  int left = 0;
  int right = 0;

  while (left != right) {
    int sum = numbers[left] + numbers[right];

    if (sum == target) {
      return {left + 1, right + 1};
    }
    if (sum < target) {
      left++;
    } else {
      right--;
    }
  }
  // not found
  return {-1, -1};
}

int main() {
  return 0;
}