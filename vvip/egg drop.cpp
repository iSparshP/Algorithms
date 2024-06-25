#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int inf=1e9;
const int N = 1010;
const int K = 1010;

int dp[N][K];


int solve(int n, int k) 
{
    if(k==1)
    {
        return n;
    }
    if(n==0)
    {
        return 0;
    }
    if(dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    dp[n][k]=inf;
    for (int i = 1; i <= n; i++) {
        dp[n][k] = min(dp[n][k], 1 + max(solve(i-1,k-1),solve(n-i,k)));
    }
    return dp[n][k];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
}
