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


// Implement a queue using 2 stacks. You will be given the following type of Q queries:
// push x - add x to the queue
// pop - pop the front element of the queue, you also have to print the element you have popped.
// front - find the element at the front of the queue


void solve()
{
	int q;
	cin>>q;
	stack<int> st1,st2;
	while(q--) 
	{
		string s;
		cin>>s;
		if(s=="push")
		{
			int n;
			cin>>n;
			st1.push(n);
		}
		else if(s=="front")
		{
			if(!st2.empty())
			{
				int a=st2.top();
				cout<<a<<endl;
			}
			else
			{
				while(!st1.empty())
				{
					st2.push(st1.top());
					st1.pop();
				}
				int a=st2.top();
				cout<<a<<endl;
			}
		}
		else if(s=="pop")
		{
			if(!st2.empty())
			{
				int a=st2.top();
				st2.pop();
				cout<<a<<endl;
			}
			else
			{
				while(!st1.empty())
				{
					st2.push(st1.top());
					st1.pop();
				}
				int a=st2.top();
				st2.pop();
				cout<<a<<endl;
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
