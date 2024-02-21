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

// You are given a string S. Find the minimum number of parentheses you should add to make the parentheses valid.
// A parentheses is valid if:
// It is an empty string
// It can be written as AB where A and B are valid parentheses
// It can be written as (A) where is a valid parentheses

// Input
// 3
// (())))
// ()()(()
// ))((

// output
// 2
// 1
// 4


void solve()
{
    string s;
    cin >> s;
    int depth = 0, ans = 0;
    char v;
    for(int i = 0; i < s.length(); i++)
    {
        v = s[i];
        if(v == '(')
        {
            depth++;
        }
        else
        {
            depth--;
            if(depth < 0)
            {
                ans += abs(depth);
                depth = 0;
            }
        }
    }
    cout << ans + depth << endl;
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
