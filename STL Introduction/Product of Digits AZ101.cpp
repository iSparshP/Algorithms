#include<bits/stdc++.h>
using namespace std;

//------------------Definition --------------//

#define ll unsigned long long int
#define fn() for(int i=0;i<n;i++)
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define endl '\n';
const int N=100010;
int inf = 1e9;
int mod = 1e9+7;


// You are given the digits of a positive number N. 
// Find the product of its digits. Since the product can be large, print it modulo 109 + 7. 
// It is guaranteed that the number begins with a non-zero digit.


void solve()
{
	int n,x;
	cin>>n;
	ll ans=1;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		ans=(ans*x)%mod;

	}
	cout<<ans<<endl;
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
