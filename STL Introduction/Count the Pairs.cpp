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
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		int j=upper_bound(arr,arr+n,x-arr[i])-arr;
		if(arr[i]<=x-arr[i])j--;
		ans+=j;
	}
	cout<<ans<<endl;
}

signed main() {
    actionbeam;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
