#include<bits/stdc++.h>

using namespace std;

//------------------Definition --------------//

#define ll unsigned long long int
#define int long long
#define fn() for(int i=0;i<n;i++)
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0)
#define endl '\n'
const int N=100010;
int inf = 1e9;
int mod = 1e9+7;

// Bob is standing in a park at (0,0) facing north. 
// He is given a series of instructions to move around the park. 
// The instructions can be:
// ‘W’: go straight 1 unit
// ‘L’: turn 90 degrees left
// ‘R’: turn 90 degrees right
// Bob has to perform the given instructions forever. 
// If he is going in a circle forever, print ‘YES’. Otherwise, print ‘NO’ (without the quotes).

// INPUT
// 3
// 3
// WWW
// 2
// LW
// 4
// WLLW

// OUTPUT
// NO
// YES
// YES

vector<int> moves[4]={{0,1},{1,0},{0,-1},{-1,0}};

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int x=0,y=0,dir=0;
	for(char i:s)
	{
		if(i=='L')
		{
			dir=(dir-1+4)%4;
		}
		else if(i=='R')
		{
			dir=(dir+1)%4;
		}
		else
		{
			x+=moves[dir][0];
			y+=moves[dir][1];
		}
	}
	if(x==0&&y==0) cout<<"YES\n";
	else if(dir!=0) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main() {
    actionbeam;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
