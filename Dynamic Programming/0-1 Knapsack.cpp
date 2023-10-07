#include<bits/stdc++.h>
using namespace std;
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int

lli N,W;
vector<int> w,v;
lli knapsack(int weight,int value)
{
    if(weight==0||value==0)
    {
        return 0;
    }
    if(w[value-1]>weight)
    {
        return knapsack(weight, value-1);
    }
    return max(v[value-1]+knapsack(weight-w[value-1],value-1), knapsack(weight,value-1));
}
int main(){
    actionbeam;
    cin>>N>>W;
    w.resize(N);
    v.resize(N);
    for(int i=0;i<N;i++)
    {
        cin>>w[i]>>v[i];
    }
    lli ans= knapsack(W,N);
    cout<<ans<<endl;
}
