class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int globalSum = nums[0];

        for(int i=1;i<nums.size();i++){
            currSum = max(nums[i],currSum+nums[i]);
            globalSum = max(currSum,globalSum);
        }
        return globalSum;
    }
};