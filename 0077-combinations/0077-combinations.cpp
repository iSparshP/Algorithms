class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp, int cur, int k, vector<int>& temp2) {
        // Base case: if we have chosen `k` elements or if `cur` goes out of bounds
        if (k == 0) {
            ans.push_back(temp2);  // Add the current combination to the result
            return;
        }
        if (cur >= temp.size()) {
            return;  // If `cur` exceeds the number of elements, stop the recursion
        }

        // Case 1: Exclude the current element and move to the next
        solve(ans, temp, cur + 1, k, temp2);

        // Case 2: Include the current element and proceed with `k-1`
        temp2.push_back(temp[cur]);
        solve(ans, temp, cur + 1, k - 1, temp2);
        temp2.pop_back();  // Backtrack after exploring the current element
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        for (int i = 1; i <= n; i++) {
            temp.push_back(i);  // Fill the `temp` array with numbers from 1 to n
        }

        vector<vector<int>> ans;
        vector<int> temp2;
        solve(ans, temp, 0, k, temp2);  // Start solving from the first element
        return ans;
    }
};
