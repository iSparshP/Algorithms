class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto &itr:nums){
            ans^=itr;
        }
        return ans;
    }
};