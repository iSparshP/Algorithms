class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return {-1,-1};
        }
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int first=(l<n && nums[l]==target)?l:-1;

        int u=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        int second=(u>0 && nums[u-1]==target)?u-1:-1;

        return {first,second};
    }
};