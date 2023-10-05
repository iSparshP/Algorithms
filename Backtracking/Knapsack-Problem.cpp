#include <bits/stdc++.h>
using namespace std;

int n,x;
int w[100100];
int p[100100];

// partial solution
int cur_sum;
vector<int> sol;

bool check(int new_w){
    if(cur_sum+new_w<=x)return 1;
    else return 0;
}

int best_ans = 0;

void rec(int level){ // 0....n-1,n
    // base case
    if(level==n){
        // is this the best profit??
        int cur_profit = 0;
        for(auto v:sol){
            cur_profit += p[v];
        }
        best_ans = max(best_ans,cur_profit);
        return;
    }
    
    // recursive case
    // take 
    if(check(w[level])){ // check
        // move
        // Add to Partial solution.
        sol.push_back(level);
        cur_sum += w[level];
        // recurse to next level.
        rec(level+1);
        // Track back (Revert Partial solution changes).
        cur_sum -= w[level];
        sol.pop_back();
    }
    // not-take
    rec(level+1);
}

int main()
{
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>w[i]>>p[i];
    }
    rec(0);
}
