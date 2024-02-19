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

// Being the site administrator, you need to register the people on the website. 
// A person registers with his name, S. 
// If the name does not occur in the records, the person gets registered on the website and “OK” is shown. 
// Otherwise, if the record already exists, print the name along with the 
// number of times the person has registered on the website before, without any spaces.



void solve()
{
	int n;
	cin>>n;
	map<string,int> mp;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(!mp.count(s))
		{
			cout<<"OK\n";
		}
		else
		{
			cout<<s<<mp[s]<<"\n";
		}
		mp[s]++;
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
