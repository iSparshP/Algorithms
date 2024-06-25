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
    
    int low=1, high = n;
    int x1=1, x2=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int blue=solve(n-mid,k);
        int green=solve(mid-1,k-1);
        if(blue>=green)
        {
            x1=mid;
            low=mid+1;
        }
        else
        {
            x2=mid;
            high=mid-1;
        }
        if(blue==green)
        {
            break;
        }
    }
    
    int val1=1+max(solve(x1-1,k-1),solve(n-x1,k));
    int val2=1+max(solve(x2-1,k-1),solve(n-x2,k));
    
    dp[n][k]=min(val1,val2);
    
    return dp[n][k];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
}
