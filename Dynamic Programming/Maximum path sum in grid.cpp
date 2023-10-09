#include<bits/stdc++.h>
using namespace std;

//------------------Definition --------------//

#define ll long long
#define f() for(ll i=0;i<n;i++)
#define sparsh cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define testcase int t;cin>>t;while(t--)
#define arrayInput for(int i=0;i<n;i++) cin>>arr[i]
#define brrayInput for(int i=0;i<n;i++) cin>>brr[i]
#define nahi cout<<"NO"<<endl
#define haan cout<<"YES"<<endl
ll n,m;
ll arr[1001][1001];
ll dp[1001][1001];
bool done[1001][1001];
//-------------------GCD ------------------//

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}


//-------------------(aX+bY=c) ------------------//
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

//------------------Solve --------------//


ll rec(ll r,ll c)
{
    // pruning
    if(r<0||c<0)
    {
        return -1e9;
    }
    // base case
    if(r==0&&c==0)
    {
        return arr[0][0];
    }
    // cache check
    if(done[r][c])
    {
        return dp[r][c];
    }
    // compute
    ll ans=-1e9;
    if(r!=0)
    {
        ans= max(ans,rec(r-1,c)+arr[r][c]);
    }
    if(c!=0)
    {
        ans= max(ans,rec(r,c-1)+arr[r][c]);
    }
    // save and return
    done[r][c]=1;
    return dp[r][c]=ans;
}

void solve()
{
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>arr[i][j];
            done[i][j]=0;
        }
    }
    cout<<rec(n-1,m-1)<<endl;
}

//------------------Main --------------//

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}


