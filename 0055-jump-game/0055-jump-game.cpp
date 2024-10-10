class Solution {
public:
    bool function(int index, int &n, vector<int>& nums, vector<int>& dp){
        //base
        if(index>=n-1){
            return true;
        }
        //cache
        if(dp[index]!=-1){
            return dp[index];
        }
        //save and compute
        int maxJump=nums[index];
        for(int i=1;i<=maxJump;i++){
            if(function(index+i,n,nums,dp))
            {
                return dp[index] = true;
            }
        }
        //return
        return dp[index]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return function(0,n,nums,dp);
    }
};