#include<bits/stdc++.h>

using namespace std;

//------------------Definition --------------//

#define ll unsigned long long int
#define int long long
#define fn() for(int i=0;i<n;i++)
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0)
#define endl '\n'
const int N=100010;
int inf = 1e9;
int mod = 1e9+7;

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int nsi[n],psi[n];
	for (int i = n-1; i >=0 ; i--)
	{
		nsi[i]=i+1;
		while(nsi[i]!=n && arr[nsi[i]] >= arr[i])
		{
			nsi[i]=nsi[nsi[i]];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		psi[i]=i-1;
		while(psi[i]!=-1 && arr[i]<arr[psi[i]])
		{
			psi[i]=psi[psi[i]];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=arr[i]*((i-psi[i])*(nsi[i]-i));
	}
	cout<<ans<<'\n';
}

signed main() {
    actionbeam;
    // int t;
    // cin>>t;
    // while(t--) {
        solve();
    // }
    return 0;
}
