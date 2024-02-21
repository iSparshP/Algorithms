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

// You have given an array A of size N and a positive integer K (≤ N). A1, A2, ..., 
// AN are the elements of the array.
// Let Bi = max (Ai, Ai+1, ..., Ai+K-1), for 1 ≤ i ≤ N - K + 1. 
// Find Bi values for all is such that 1 ≤ i ≤ N - K + 1.

// Input
// 4
// 9 3
// 1 2 3 1 4 5 2 3 6
// 5 5
// 1 -4 3 -3 -9
// 4 1
// -3 1 -8 3
// 5 2
// -1 -1 -1 -1 -1

// output
// 3 3 4 5 5 5 6
// 3
// -3 1 -8 3
// -1 -1 -1 -1

struct monotone_deuque
{
	deque<int> dq;
	void insert(int x)
	{
		if(!dq.empty() && dq.back()<x)
		{
			dq.pop_back();
		}
		dq.push_back(x);
	}
	void remove(int x)
	{
		if(dq.front()==x)
		{
			dq.pop_front();
		}
	}
	int get_max()
	{
		return dq.front();
	}
};

void solve()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	monotone_deuque mt;
	for(int i=0;i<n;i++)
	{
		mt.insert(arr[i]);
		if(i-k>=0)
		{
			mt.remove(arr[i-k]);
		}
		if(i>=k-1)
		{
			cout<<mt.get_max()<<" ";
		}
	}
	cout<<endl;

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
