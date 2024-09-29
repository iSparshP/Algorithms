class Solution {
public:
    int solve(int n,vector<int>& dp){
        //pruning
        if(n<0){
            return 0;
        }
        //base
        if(n==0){
            return 1;
        }
        //cache
        if(dp[n]!=-1){
            return dp[n];
        }
        //save and compute
        dp[n]= solve(n-1,dp)+solve(n-2,dp);
        //return 
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};