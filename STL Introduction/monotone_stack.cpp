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
	strategy 1
	stack<int> st;
	int ngi[n];
	// iterate backwards
	for (int i = n-1; i>=0; i--)
	{
		// remove non-possible index
		while(!st.empty() && arr[st.top() <= arr[i]])
		{
			st.pop();
		}
		// get the answer for current index and push current
		if(st.empty())
		{
			ngi[i]=n;
		}
		else
		{
			ngi[i]=st.top();
		}
		st.push(i);
	}


	// strategy 2
	int nextg[n];
	for (int i = n-1; i>=0; i--)
	{
		nextg[i]=i+1;
		while(nextg[i]!=n && arr[i]<arr[nextg[i]])
		{
			nextg[i]=nextg[nextg[i]];
		}
	}

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
