#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll testCases;
   cin>>testCases;
   while(testCases--)
   {
     ll n,k,s;
     cin>>n>>k>>s;
     ll arr[n+1];
     ll prefix[n+1];
     prefix[0] = 0;
     ll ans = -1e18;
     for(ll i=1;i<=n;i++){
       cin>>arr[i];
       prefix[i]=prefix[i-1]+arr[i];
     }
     ll cntOdd = 0;
     multiset < ll > currWindowPrefixSum;
     currWindowPrefixSum.insert(0);
     ll prev = 1;
     for(ll i=1;i<=n;i++){
       cntOdd+=(abs(arr[i])%2);
       if(cntOdd>k){
           while(prev<=i){
               currWindowPrefixSum.erase(currWindowPrefixSum.find(prefix[prev-1]));
               if(abs(arr[prev])%2){
                   prev++;
                   cntOdd--;
                   break;
               }
               prev++;
           }
       }
       if(!currWindowPrefixSum.empty()){
           auto itr = currWindowPrefixSum.lower_bound(prefix[i]-s);
           if(itr!=currWindowPrefixSum.end()){
               ans = max(ans,prefix[i]-(*itr));
           }
       }
       currWindowPrefixSum.insert(prefix[i]);
     }
     if(ans==-1e18){
       cout<<"IMPOSSIBLE\n";
       continue;
     }
     cout<<ans<<"\n";
 }

}
