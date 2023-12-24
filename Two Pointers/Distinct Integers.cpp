#include <bits/stdc++.h>
using namespace std;
int frequency[1000001];
long long countAtmostK(int n, int arr[], int k){
   long long ans = 0;
   int head = 0;
   int tail = 0;
   int cnt =  0;
   while(tail<n){
       if(!frequency[arr[tail]])
           cnt++;
       frequency[arr[tail]]++;
       while(head<=tail and cnt>k)
       {
           frequency[arr[head]]--;
           if(!frequency[arr[head]])
               cnt--;
           head++;
       }
       ans+=(tail-head+1);
       tail++;
   }
   return ans;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       int n,k;
       cin>>n>>k;
       int arr[n];
       for(int i=0;i<n;i++)
           cin>>arr[i];
       long long ans = countAtmostK(n,arr,k);
       for(int i=0;i<n;i++)
           frequency[arr[i]] = 0;
       ans-=countAtmostK(n,arr,k-1);
       for(int i=0;i<n;i++)
           frequency[arr[i]] = 0;
       cout<<ans<<"\n";
   }
}
