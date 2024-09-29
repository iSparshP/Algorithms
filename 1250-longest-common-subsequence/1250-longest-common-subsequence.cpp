class Solution {
public:
    // ((Memoization))
    // int lcs(string text1, string text2,int i,int j,vector<vector<int>>& dp){
    //     //base
    //     if(text1.size()<=i || text2.size()<=j){
    //         return 0;
    //     }
    //     //cache
    //     if(dp[i][j]!=-1){
    //         dp[i][j];
    //     }
    //     //compute and save
    //     int ans=0;
    //     ans=max(ans,lcs(text1,text2,i+1,j,dp));
    //     ans=max(ans,lcs(text1,text2,i,j+1,dp));
    //     if(text1[i]==text2[j]){
    //         ans=max(ans,1+lcs(text1,text2,i+1,j+1,dp));
    //     }
    //     //return
    //     dp[i][j]=ans;
    //     return dp[i][j];
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};