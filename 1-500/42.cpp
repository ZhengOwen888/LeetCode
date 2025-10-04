// 42. Trapping Rain Water

#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
  int left = 0;
  int right = height.size() - 1;
  int level = 0; // Current water level (max height we've seen from the smaller side)
  int res = 0;   // Total trapped water

  // Process until both pointers meet
  while (left <= right) {

    // If the left bar is lower (or equal), we can safely compute water on the left
    while (left <= right && height[left] <= height[right]) {
      // Update the water level based on the current left height
      level = max(level, height[left]);
      // Water trapped at this position = level - current height (if positive)
      int area = level - height[left];
      res += max(area, 0);

      // Move inward from the left
      left++;
    }

    // Otherwise, process the right side
    while (right >= left && height[right] <= height[left]) {
      // Update the water level based on the current right height
      level = max(level, height[right]);
      // Water trapped at this position = level - current height (if positive)
      int area = level - height[right];
      res += max(area, 0);

      // Move inward from the right
      right--;
    }
  }

  return res;
}

int main() {
  vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> height2 = {4, 2, 0, 3, 2, 5};

  int area1 = trap(height1);
  int area2 = trap(height2);

  cout << "  Area 1: " << boolalpha << (area1 == 6) << noboolalpha << endl;
  cout << "expected: " << 6 << "  | actual: " << area1 << endl;

  cout << "  Area 2: " << boolalpha << (area2 == 9) << noboolalpha << endl;
  cout << "expected: " << 9 << "  | actual: " << area2 << endl;


  return 0;
}