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
// add x - add element x at the end of vector
// remove - delete last element of the vector, if vector is not empty
// print x - print the x-th character of the vector, if it exists, otherwise print 0. (0-indexing)
// clear - empty the vector

void solve()
{
	int q;
	cin>>q;
	vector<int> vec;
	while(q--)
	{
		string s;
		cin>>s;
		int n;
		if(s=="add")
		{
			cin>>n;
			vec.push_back(n);
		}
		else if(s=="print")
		{
			cin>>n;
			if(vec.size()>n)
			{
				cout<<vec[n]<<endl;
			}
			else
			{
				cout<<"0"<<endl;
			}
		}
		else if(s=="remove" && !vec.empty())
		{
			vec.pop_back();
		}
		else if(s=="clear")
		{
			vec.clear();
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
