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
#define int long long

// You are given N blocks. 
// You have to build towers by placing blocks on top of each other 
// with the condition that the upper block must be smaller than the lower block. 
// You have to process the blocks in the given order. 
// Find the minimum possible number of towers you can create.

// input
// 3
// 5
// 3 2 5 1 4
// 4
// 1 1 1 1
// 5
// 5 4 5 3 2 

// 3
// 5
// 3 2 5 1 4
// 4
// 1 1 1 1
// 5
// 5 4 5 3 2 

void solve()
{
	int n;
	cin>>n;
	multiset<int>ml;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		auto it=ml.upper_bound(x);
		if(it==ml.end())
		{
			ml.insert(x);
		}
		else
		{
			ml.erase(it);
			ml.insert(x);
		}
	}
	cout<<ml.size()<<endl;
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
