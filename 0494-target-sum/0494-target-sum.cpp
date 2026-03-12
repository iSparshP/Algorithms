class Solution {
public:
    int recursion(int idx, vector<int>& nums, int target){
        //Base
        if(idx==nums.size()) return target ==0;
        //Recursion
        int plus = recursion(idx+1,nums,target-nums[idx]);

        int minus = recursion(idx+1,nums,target+nums[idx]);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(0, nums, target);
    }
};