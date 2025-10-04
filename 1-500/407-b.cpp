// 407. Trapping Rain Water (Faster Version)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int trapRainWater(vector<vector<int>> &heightMap) {
  vector<vector<int>> direction = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // top left bottom right

  size_t numRows = heightMap.size();
  size_t numCols = heightMap[0].size();

  priority_queue<
      pair<int, pair<int, int>>,
      vector<pair<int, pair<int, int>>>,
      greater<pair<int, pair<int, int>>>>
      minHeap;
  vector<vector<int>> visited(numRows, vector<int>(numCols, 0)); // Tracks visited positions

  for (auto row = 0; row < numRows; row++) {
    for (auto col = 0; col < numCols; col++) {
      if (row == 0 || row == numRows - 1 || col == 0 || col == numCols - 1) {
        minHeap.push(make_pair(heightMap[row][col], make_pair(row, col)));
        visited[row][col] = 1; // mark the position as visited
      }
    }
  }

  int volume = 0;
  int level = 0;

  while (!minHeap.empty()) {
    auto pos = minHeap.top();
    minHeap.pop();

    auto [height, coord] = pos;
    auto [row, col] = coord;

    level = max(level, height);
    volume += level > height ? level - height : 0;

    for (const auto &dir : direction) {
      // neighboring positions
      int r = row + dir[0];
      int c = col + dir[1];

      if (
        r >= 0 && r < numRows &&
        c >= 0 && c < numCols &&
        visited[r][c] != 1
      ) {
        minHeap.push(make_pair(heightMap[r][c], make_pair(r, c)));
        visited[r][c] = 1;
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