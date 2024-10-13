class Solution {
public:
    int helper(int n,vector<int>& dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int mincount=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int result = 1 + helper(n-i*i,dp);
            mincount = min(mincount, result);
        }
        return dp[n] = mincount;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        // memset(dp,-1,sizeof(dp));
        return helper(n,dp);
    }
};