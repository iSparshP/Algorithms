class Solution {
public:
    vector<vector<int>> ans;
    void recursion(int idx, vector<int>& nums, vector<int>& res) {
        ans.push_back(res);
        for (int i = idx; i < nums.size(); i++) {
            res.push_back(nums[i]);
            recursion(i + 1, nums, res);
            res.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        recursion(0, nums, res);
        return ans;
    }
};