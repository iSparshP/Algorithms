#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       ll n,target;
       cin>>n>>target;
       vector< ll > arr(n);
       for(int i=0;i<n;i++)
           cin>>arr[i];
       sort(arr.begin(),arr.end());
       ll best = arr[0]+arr[1]+arr[2];
       for(ll i=1;i<(ll)arr.size()-1;i++){
           ll lo = 0;
           ll hi = (ll)arr.size()-1;
           while(1){
               if(abs(arr[lo]+arr[i]+arr[hi]-target)<abs(best-target)){
                   best=arr[lo]+arr[i]+arr[hi];
               }
               if(arr[lo]+arr[i]+arr[hi]>target)hi--;
               else lo++;
               if(lo==i||hi==i)break;
           }
       }
       cout<<abs(best-target)<<"\n";
   }
}
