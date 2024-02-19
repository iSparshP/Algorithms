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
// insertback x - add element x at the end of deque
// eraseback - delete end element of the queue, if queue is not empty
// insertfront x - add element x at the front of deque
// erasefront - delete front element of the queue, if queue is not empty
// printfront - print element at front of the queue, if queue is not empty, otherwise print 0
// printback - print element at back of the queue , if queue is not empty, otherwise print 0
// print x - print the x-th character of the vector, if it exists, otherwise print 0. (0-indexing)

void solve()
{
	int q;
	cin>>q;
	deque<int> dq;
	while(q--)
	{
		string s;
		cin>>s;
		int x;
		if(s=="insertback")
		{
			cin>>x;
			dq.push_back(x);
		}
		else if(s=="eraseback")
		{
			if(!dq.empty())
			{
				dq.pop_back();
			}
		}
		else if(s=="insertfront")
		{
			cin>>x;
			dq.push_front(x);
		}
		else if(s=="erasefront")
		{
			if(!dq.empty())
			{
				dq.pop_front();
			}
		}
		else if(s=="printfront")
		{
			if(!dq.empty())
			{
				cout<<dq.front()<<endl;
			}
			else
			{
				cout<<"0"<<endl;
			}
		}
		else if(s=="printback")
		{
			if(!dq.empty())
			{
				cout<<dq.back()<<endl;
			}
			else
			{
				cout<<"0"<<endl;
			}		
		}
		else if(s=="print")
		{
			int x;
			cin>>x;
			if(x<dq.size())
			{
				cout<<dq[x]<<endl;
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
