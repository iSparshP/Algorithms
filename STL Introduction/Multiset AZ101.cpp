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
// erase x - delete one element with value x, if it exists
// eraseall x - delete all elements with value x, if it exists
// find x - if x is present print “YES”, else print “NO”
// count x - print the number of times x occurs in the set
// print - print the values in set
// empty - empty the set

void solve()
{
	int q;
	cin>>q;
	multiset<int> ms;
	while(q--)
	{
		string s;
		cin>>s;
		int n;
		if(s=="add")
		{
			cin>>n;
			ms.insert(n);
		}
		else if(s=="erase")
		{
			cin>>n;
			if(ms.find(n)!=ms.end())
			{
				ms.erase(ms.find(n));
			}
		}
		else if(s=="eraseall")
		{
			cin>>n;
			ms.erase(n);
		}
		else if(s=="find")
		{
			cin>>n;
			if(ms.find(n)!=ms.end())
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}	
		}
		else if(s=="count")
		{
			cin>>n;
			int count=0;
			for(auto num:ms)
			{
				if(num==n)
				{
					count++;
				}
			}
			cout<<count<<endl;
		}
		else if(s=="print")
		{
			for(auto num:ms)
			{
				cout<<num<<" ";
			}
			cout<<endl;
		}
		else if(s=="empty")
		{
			ms.clear();
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
