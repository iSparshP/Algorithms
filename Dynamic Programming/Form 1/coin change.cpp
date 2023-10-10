#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int n;
int der[1005];
bool dp[1005][1005];
bool done[1005][1005];

bool rec(int level, int target)
{
    //pruning
    if(target<0)
    {
        return false;
    }
    //basecase
    if(level==n)
    {
        if(target==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //chache check
    if(done[level][target])
    {
        return dp[level][target];
    }
    //compute
    bool ans=rec(level+1,target)||rec(level,target-der[level]);
    //save&return
    dp[level][target]=ans;
    done[level][target]=true;
    return ans;
    
}
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>der[i];
    }
    int target;
    cin>>target;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<target;j++)
        {
            done[i][j]=false;
        }
    }
    cout<<rec(0,target)<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
