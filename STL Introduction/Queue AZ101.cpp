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
// add x - add element x at the end of queue
// remove- delete front element of the queue, if queue is not empty
// print - print the element at the first position, if queue is not empty, otherwise print 0


void solve()
{
	int q;
	cin>>q;
	queue<int> que;
	while(q--)
	{
		string s;
		cin>>s;
		int n;
		if(s=="add")
		{
			cin>>n;
			que.push(n);
		}
		else if(s=="print")
		{
			if(!que.empty())
			{
				cout<<que.front()<<endl;
			}
			else
			{
				cout<<"0"<<endl;
			}
		}
		else if(s=="remove" && !que.empty())
		{
			que.pop();
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