class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
    }
    int mincost(vector<int>& cost, int n, vector<int>& dp){
        //pruning
        if(n<0){
            return 0;
        }
        //base case
        if(n==0||n==1){
            return cost[n];
        }
        //cache
        if(dp[n]!=-1){
            return dp[n];
        }
        //save and compute
        dp[n]=cost[n]+min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
        //return
        return dp[n];
    }
};