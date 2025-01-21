class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long first = accumulate(begin(grid[0]), end(grid[0]), 0LL),
                  second = 0;
        long long Sum = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            first -= grid[0][turnIndex];
            Sum = min(Sum, max(first, second));
            second += grid[1][turnIndex];
        }
        return Sum;
    }
};