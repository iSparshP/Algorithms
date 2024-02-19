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

// You are given Q queries and have to perform the following operations:
// add x - add element x in the set
// erase x - delete element with value x, if it exists
// find x - if x is present print “YES”, else print “NO”
// print - print the values in set
// empty - empty the set



void solve()
{
	int q;
	cin>>q;
	set<int> st;
	while(q--)
	{
		string s;
		cin>>s;
		int n;
		if(s=="add")
		{
			cin>>n;
			st.insert(n);
		}
		else if(s=="erase")
		{
			cin>>n;
			st.erase(n);
		}
		else if(s=="find")
		{
			cin>>n;
			auto it= st.find(n);
			if(it != st.end())
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		else if(s=="print")
		{
			for(auto &v: st)
			{
				cout<<v<<" ";
			}
			cout<<"\n";
		}
		else if(s=="empty")
		{
			st.clear();
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
