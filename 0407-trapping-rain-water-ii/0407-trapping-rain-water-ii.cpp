class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j : {0, n - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i : {0, m - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int waterTrapped = 0;
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int row = cell.first;
            int col = cell.second;
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    waterTrapped += max(0, height - heightMap[newRow][newCol]);
                    minHeap.push({max(height, heightMap[newRow][newCol]), {newRow, newCol}});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return waterTrapped;
    }
};
