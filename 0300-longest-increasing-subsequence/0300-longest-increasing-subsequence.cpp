class Solution {
public:
    int solve(int level,vector<int>& nums,vector<int>&dp){
        //pruning
        if(level<0){
            return 0;
        }
        //base

        //cache
        if(dp[level]!=-1){
            return dp[level];
        }
        //save and compute
        int ans=1;
        for(int previous=0;previous<level;previous++){
            if(nums[previous]<nums[level]){
                ans=max(ans,1+solve(previous,nums,dp));
            }
        }
        //return 
        return dp[level]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int best=0;
        for(int i=0;i<n;i++){
            best=max(best,solve(i,nums,dp));
        }
        return best;
    }
};