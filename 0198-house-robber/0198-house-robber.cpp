class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int n, int i){
        //base
        if(i>=n)
        {
            return 0;
        }
        //cache
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        //compute and save
        int take=nums[i]+solve(nums,n,i+2);
        int notTake=solve(nums,n,i+1);
        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,nums.size(),0);
    }
};