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

// You have an empty set and can perform the following operations on it:
// 1 x - Add integer x to the set
// 2 x - Find the smallest integer that is not present in the set, which is greater than or equal to x.

void solve()
{
	int q;
	cin>>q;
	set<int> s,ns;
	while(q--)
	{
		int n,x;
		cin>>n>>x;
		if(n==1)
		{
			s.insert(x);
			ns.erase(x);
			if(!s.count(x+1))
			{
				ns.insert(x+1);
			}
		}
		else
		{
			if(!s.count(x))
			{
				cout<<x<<endl;
			}
			else
			{
				cout<<*ns.lower_bound(x)<<endl;
			}
		}
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
