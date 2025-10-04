// 407. Trapping Rain Water II
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <tuple>

using namespace std;

template <typename T>
auto makeMinHeap() {
  priority_queue<T, vector<T>, greater<T>> minHeap;
  return minHeap;
}

// Calculates Volume of Rain Water Trapped in Pot Holes (2d Matrix)
int trapRainWater(vector<vector<int>> &heightMap) {

  auto minHeap = makeMinHeap<vector<int>>(); // (height, row, col)
  size_t numRows = heightMap.size();
  size_t numCols = heightMap[0].size();

  // Store border in min heap and mark them as visited
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      if (row == 0 || row == numRows - 1 || col == 0 || col == numCols - 1) {
        minHeap.push({heightMap[row][col], row, col});
        heightMap[row][col] = -1; // mark as visited
      }
    }
  }

  int volume = 0; // total rain water trapped
  int level = 0;  // represents the minimum height around a position

  while (!minHeap.empty()) {
    auto pos = minHeap.top(); // get minimum height from current position
    minHeap.pop();
    int height = pos[0], row = pos[1], col = pos[2];

    // update the level when height popped off from current position is higher than current level
    level = max(level, height);

    // Check if current minimum level is greater than the height we just popped off
    // true : volume += level - height
    // false: volume += 0
    volume += level > height ? level - height : 0;

    /*
      The Logic is that by using a min heap, you can keep track of the minimum boundary height.
      This is why level - height works and gives you the volume contained in the current position
    */

    // top, right, bottom, left
    vector<vector<int>> neighbors = {{row - 1, col}, {row, col + 1}, {row + 1, col}, {row, col - 1}};

    // add current position's unvisted neighbor
      for (const auto &n : neighbors) {
        int row = n[0];
        int col = n[1];
        if (
            row >= 0 && row < numRows &&
            col >= 0 && col < numCols &&
            heightMap[row][col] != -1)
        {
          minHeap.push({heightMap[row][col], row, col});
          heightMap[row][col] = -1;
        }
      }
    }

    return volume;
  }
int main() {

  vector<vector<int>> heightMap1 = {
    {1, 4, 3, 1, 3, 2},
    {3, 2, 1, 3, 2, 4},
    {2, 3, 3, 2, 3, 1}
  };
  vector<vector<int>> heightMap2 = {
    {3, 3, 3, 3, 3},
    {3, 2, 2, 2, 3},
    {3, 2, 1, 2, 3},
    {3, 2, 2, 2, 3},
    {3, 3, 3, 3, 3}
  };

  int volume1 = trapRainWater(heightMap1);
  int volume2 = trapRainWater(heightMap2);

  cout << "Volume 1: " << boolalpha << (volume1 == 4) << noboolalpha << endl;
  cout << "expected: " << 4  << "  | actual: " << volume1 << endl;

  cout << "Volume 2: " << boolalpha << (volume2 == 10) << noboolalpha << endl;
  cout << "expected: " << 10 << "  | actual: " << volume2 << endl;

  return 0;
}