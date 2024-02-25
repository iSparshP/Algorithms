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
// add x y - add student name X (string) for marks y (integer). If it already exists, add a new entry.
// erase x - erase the first current entry of student with name x
// eraseall x - erase all entries of student with name x
// print x - print the first entry of marks of student with name x, if entry is not there for x, print 0.

// INPUT
// 1
// 9
// add alice 24
// add bob 21
// add alice 23
// add alice 22
// print alice
// erase alice
// print alice
// eraseall alice
// print alice

// OUTPUT
// 24
// 23
// 0

void solve()
{
	int q;
	cin>>q;
	multimap<string, int> m;
	while(q--)
	{
		string s;
		cin>>s;
		if(s=="add")
		{
			string x;
			int y;
			cin>>x>>y;
			m.insert({x,y});
		}
		else if(s=="erase")
		{
			string x;
			cin>>x;
			auto it = m.find(x);
			if(it != m.end())
			{
				m.erase(it);
			}
		}
		else if(s=="eraseall")
		{
			string x;
			cin>>x;
			if(m.find(x)!=m.end())
			{
				m.erase(x);
			}
		}
		else
		{
			string x;
			cin>>x;
			auto it=m.find(x);
			if(it!=m.end())
			{
				cout<<it->second<<endl;
			}
			else
			{
				cout<<"0\n";
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
