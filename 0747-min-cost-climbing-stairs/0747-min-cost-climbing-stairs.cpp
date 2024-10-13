class Solution
{
    public:
        int minCostClimbingStairs(vector<int> &cost)
        {
            int n = cost.size();
            if (n < 2)
            {
                return n == 0 ? 0 : cost[0];
            }

            vector<int> dp(n);
            dp[0] = cost[0];
            dp[1] = cost[1];

            for (int i = 2; i < n; i++)
            {
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            }

            return min(dp[n - 1], dp[n - 2]);
        }
   	// int mincost(vector<int>& cost, int n, vector<int>& dp){
   	//    	//pruning
   	//     if(n < 0){
   	//         return 0;
   	//     }
   	//    	//base case
   	//     if(n==0||n==1){
   	//         return cost[n];
   	//     }
   	//    	//cache
   	//     if(dp[n]!=-1){
   	//         return dp[n];
   	//     }
   	//    	//save and compute
   	//     dp[n]=cost[n]+min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
   	//    	//return
   	//     return dp[n];
   	// }
};