class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
      int m = heightMap.size();
        int n = heightMap[0].size();
        
        // Edge case: If the matrix has less than 3 rows or columns, no water can be trapped
        if (m < 3 || n < 3) return 0;

        // Min-heap to store boundary cells with their heights
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the heap and mark them as visited
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }

        // Directions for moving to adjacent cells (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int waterTrapped = 0;

        // Process the heap
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first, y = cell.second;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    // Calculate water trapped if the cell is lower than the current boundary height
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    // Push the next cell into the heap with the max height between the boundary and its height
                    minHeap.push({max(height, heightMap[nx][ny]), {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped;

    }
};