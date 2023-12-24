#include <bits/stdc++.h>
using namespace std;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       int n,k;
       cin>>n>>k;
       int arr[n];
       int diff[n-1];
       for(int i=0;i<n;i++)
           cin>>arr[i];
       for(int i=1;i<n;i++)
           diff[i-1] = arr[i]-arr[i-1];
       int ans = 2e9;
       int window = n-k-1;
       deque < int > q;
       for(int i=0;i<n-1;i++){
           while(!q.empty() and i-q.front()+1>window)
               q.pop_front();
           while(!q.empty() and diff[i]>=diff[q.back()])
               q.pop_back();
           q.push_back(i);
           if(i>=window-1)
               ans = min(ans,diff[q.front()]);
       }
       cout<<ans<<"\n";
   }
}
