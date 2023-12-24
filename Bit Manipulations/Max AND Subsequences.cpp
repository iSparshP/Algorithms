#include <bits/stdc++.h>
using namespace std;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   int testCase;
   cin>>testCase;
   while(testCase--){
       int n,x;
       cin>>n>>x;
       vector < int > arr(n);
       for(int i=0;i<n;i++)
           cin>>arr[i];
       int ans = 0;
       for(int i=29;i>=0;i--){
           vector < int > elementBitSet;
           for(auto v:arr){
               if(v&(1LL<<i))
                   elementBitSet.push_back(v);
           }
           if(elementBitSet.size()>=x){
               ans+=(1LL<<i);
               arr = elementBitSet;
           }
       }
       cout<<ans<<"\n";
   }

}
