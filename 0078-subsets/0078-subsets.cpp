class Solution {
public:
    vector<vector<int>> ans;

    void recursion(int idx, vector<int>& nums, vector<int>& res) {
        // store current subset
        ans.push_back(res);

        for(int i = idx; i < nums.size(); i++) {
            res.push_back(nums[i]);          // choose
            recursion(i + 1, nums, res);    // explore
            res.pop_back();                 // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        recursion(0, nums, res);
        return ans;
    }
};