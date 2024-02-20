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

// You are given an array of N integers. For each position, 
// find the nearest position to its left having a smaller value. (1-based indexing)

void solve()
{
	int n;
	cin>>n;
	int a[n];
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		while (!st.empty() && a[st.top()] >= a[i])
		{
			st.pop();
		}
		if(st.empty())
		{
			cout<<"0 ";
		}
		else
		{
			cout<<st.top() + 1<<" ";
		}
		st.push(i);
	}
	cout<<"\n";
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
