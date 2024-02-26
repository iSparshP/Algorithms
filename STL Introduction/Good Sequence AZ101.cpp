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

// You are given an array A of N integers. 
// A sequence is called good if the value x occurs x times in the array. 
// Find the minimum number of integers you need to delete from A to make it good.

// INPUT
// 3
// 5
// 3 2 3 3 1
// 4
// 3 2 2 4
// 5
// 6 6 1 1 2

// OUTPUT
// 1
// 2
// 4

void solve()
{
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		mp[x]++;
	}
	int ans=0;
	for(auto it:mp)
	{
		if(it.second>=it.first)
		{
			ans+=it.second-it.first;
		}
		else
		{
			ans+=it.second;
		}
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
