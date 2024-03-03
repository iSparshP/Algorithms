#include<bits/stdc++.h>

//------------------Definition --------------//

#define ll unsigned long long int
#define int long long
#define fn() for(int i=0;i<n;i++)
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0)
#define endl '\n'
const int N=100010;
int inf = 1e9;
int mod = 1e9+7;

// You are given a list of N students with their names and roll number. 
// Sort the list according to their roll numbers.

// INPUT
// 2
// 5
// amelia 21
// sophia 12
// emma 11
// ava 8
// isabel 1
// 3
// alice 34
// bob 20
// hannah 5

// OUTPUT
// isabel 1
// ava 8
// emma 11
// sophia 12
// amelia 21
// hannah 5
// bob 20
// alice 34

bool comp(pair<string,int> a, pair<string,int>b)
{
	return a.second<b.second;
}

void solve()
{
	int n;
	cin>>n;
	vector<pair<string, int>> v;
	for (int i = 0; i < n; ++i)
	{
		string s;
		int r;
		cin>>s>>r;
		v.push_back({s,r});
	}
	sort(v.begin(),v.end(),comp);
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
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
