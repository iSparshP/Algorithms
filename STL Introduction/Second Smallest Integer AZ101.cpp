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


// You are given an array of N integers. You have to find the second smallest integer in the given array.

void solve()
{
	int n;
	cin>>n;
	set<int> st;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		st.insert(x);
	}
	st.erase(st.begin());
	if(st.empty())
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<*st.begin()<<endl;
	}
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
