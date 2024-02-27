#include<bits/stdc++.h>
using namespace std;

//------------------Definition --------------//

#define ll unsigned long long int
#define int long long
#define fn() for(int i=0;i<n;i++)
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define endl '\n';
const int N=100010;
int inf = 1e9;
int mod = 1e9+7;

// You are given an array A of size N. You have to answer the following queries
// 1 x - Find the smallest Element ≥ x 
// 2 x - Find the smallest Element > x 
// 3 x - Find the number of elements ≤ x
// 4 x - Find the number of elements < x
// If the answer does not exist print -1.

// INPUT
// 2
// 5 4
// 1 2 2 3 4
// 1 2
// 2 2
// 3 4
// 3 2
// 3 2
// 5 5 5
// 3 5
// 4 5

// OUTPUT
// 2 3 5 3 
// 3 0 


void solve()
{
	int n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	while(q--)
	{
		int num,x;
		cin>>num>>x;
		if(num==1)
		{
			int i=lower_bound(arr,arr+n,x)-arr;
			if(i==n)
			{
				cout<<"-1"<<" ";
			}
			else
			{
				cout<<arr[i]<<" ";
			}
		}
		else if(num==2)
		{
			int i=upper_bound(arr,arr+n,x)-arr;
			if(i==n)
			{
				cout<<"-1"<<" ";
			}
			else
			{
				cout<<arr[i]<<" ";
			}
		}
		else if(num==3)
		{
			auto i=upper_bound(arr,arr+n,x)-arr;
			cout<<i<<" ";
		}
		else
		{
			auto i=lower_bound(arr,arr+n,x)-arr;
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

signed main()
{
    actionbeam;
    int t;
    cin>>t;
    while(t--)
    {
    	solve();
    }
}
