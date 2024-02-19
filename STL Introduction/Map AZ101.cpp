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
// add x y - add student name X (string in lowercase alphabets) with marks y (integer). 
// If it already exists, update.
// erase x - erase marks of student with name x, if the entry exists
// print x - print marks of student with name x, if entry is not there for x, print 0.

void solve()
{
	int q;
	cin>>q;
	map<string,int> mp;
	map<string,int>:: iterator it;
	while(q--)
	{
		string s;
		cin>>s;
		string x;
		int y;
		if(s=="add")
		{
			cin>>x>>y;
			if(mp.find(x) != mp.end())
			{
				mp[x]=y;
			}
			else
			{
				mp.insert(pair<string,int>(x,y));
			}
		}
		else if(s=="erase")
		{
			cin>>x;
			if(mp.find(x) != mp.end())
			{
				mp.erase(x);
			}
		}
		else if(s=="print")
		{
			cin>>x;
			if(mp.find(x) != mp.end())
			{
				cout<<mp[x]<<endl;
			}
			else
			{
				cout<<"0"<<endl;
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
