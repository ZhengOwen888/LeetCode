// 15. 3Sum
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;

  for (int cur = 0; cur < nums.size(); cur++) {
    if (cur > 0 && nums[cur] == nums[cur - 1]) continue; // prevent duplicate answers
    int left = cur + 1;
    int right = nums.size() - 1;

    // two sum problem
    while (left < right) {
      int total = nums[left] + nums[right] + nums[cur];
      if (total == 0) {
        res.push_back({nums[cur], nums[left], nums[right]});

        // prevent duplicate answers
        while (left < right && nums[left] == nums[left + 1]) left++;
        while (left < right && nums[right] == nums[right - 1]) right--;
        left++;
        right--;

      } else if (total < 0) {
        left++;

      } else {
        right--;
      }
    }
  }
  return res;
}

int main() {
  return 0;
}