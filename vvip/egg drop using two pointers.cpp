#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int inf=1e9;
const int N = 1010;
const int K = 1010;

int dp[N][K];

int main()
{
    int N,K;
    cin>>N>>K;
    int dp[N][K];
    for (int n = 1; n <= N; n++) {
        dp[n][1]=n;
    }
    for(int k=2;k<=K;k++)
    {
        dp[1][k]=0;
        int xopt=1;
        for(int n=2;n<=N;n++)
        {
            while(xopt<n && max(dp[xopt-1][k-1], dp[n-xopt][k]) > max(dp[xopt+1-1][k-1], dp[n-(xopt+1)][k]))
            {
                xopt++;
            }
            dp[n][k]= 1+max(dp[xopt-1][k-1],dp[n-xopt][k]);
        }
    }
    cout<<dp[N][K];
    return 0;
}
