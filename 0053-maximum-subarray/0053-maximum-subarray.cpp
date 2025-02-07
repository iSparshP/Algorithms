class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN;
        int curr=0;
        for(int &num:nums){
            curr=max(num,curr+num);
            max_sum=max(max_sum,curr);
        }
        return max_sum;
    }
};