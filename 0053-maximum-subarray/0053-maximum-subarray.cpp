class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum=0;
        int maximumSum=INT_MIN;
        for(auto& sum:nums){
            currentSum=max(sum,currentSum+sum);
            maximumSum=max(currentSum,maximumSum);
        }
        return maximumSum;
    }
};