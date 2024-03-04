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

// You are given an integer N. 
// You have to find all the permutations of N in lexicographic order.

// INPUT
// 3

// OUTPUT
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1


void solve() {
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 1; i <= n; ++i) { // Changed loop to start from 1
        v.push_back(i);
    }
    do {
        for(int i=0;i<n;i++) {
            cout<<v[i]<<" ";
        }
        cout << endl; // Added newline after printing each permutation
    } while(next_permutation(v.begin(),v.end()));
}

signed main() {
    actionbeam;
    // int t;
    // cin>>t;
    // while(t--) {
        solve();
    // }
    return 0; // Added return statement to main
}
