from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
        ans = 0
        
        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                if matrix[i][j] == "1":
                    if i == n-1 or j == m-1:
                        dp[i][j] = 1
                    else:
                        mini = min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1])
                        dp[i][j] = mini + 1
                    ans = max(ans, dp[i][j])
                    
        return ans * ans
