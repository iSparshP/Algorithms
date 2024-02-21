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

// There are N students in section A. 
// The i-th student got Ai marks. 
// The class teacher of section B was absent so sections A and B were merged. 
// The students of section B did not want to humiliate themselves, 
// so they decided to sit with students having the same marks as them. 
// You are given the marks of students of section B in order of their entry in the class. 
// You have to tell whether the i-th student of section B can sit with a student with the same marks as him. 
// If there is at least 1 person in the room with the same marks, print ‘YES’ else print ‘NO’. 
// (without the quotes)
// See Sample Test Cases.

// Input
// 2

// 3 5

// 2 5 4

// 7 4 1 4 5

// 4 4

// 1 1 8 2

// 8 3 3 5

// output
// NO
// YES
// NO
// YES
// YES
// YES
// NO
// YES
// NO


void solve()
{
	int n,m;
	cin>>n>>m;
	int array1[n];
	int array2[m];
	set<int> st;
	for(int i=0;i<n;i++)
	{
		cin>>array1[i];
		st.insert(array1[i]);
	}
	for(int i=0;i<m;i++)
	{
		cin>>array2[i];
		if(st.find(array2[i])!=st.end())
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
			st.insert(array2[i]);
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
