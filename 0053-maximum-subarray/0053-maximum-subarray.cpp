class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current=0;
        int maxSub=INT_MIN;
        for(auto &num:nums){
            current=max(num,current+num);
            maxSub=max(current,maxSub);
        }
        return maxSub;
        
    }
};