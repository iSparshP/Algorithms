#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int n,k;
bool check(int x)
{
   int cnt = 0,i;
   for(i=0;i<x;i++)
   {
       if(arr[i]==0)
           cnt++;
   }
   if(cnt<=k)
       return true;
   for(i=x;i<n;i++)
   {
       if(arr[i-x]==0)
           cnt--;
       if(arr[i]==0)
           cnt++;
       if(cnt<=k)
           return true;
   }
   return false;
}
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       int i;
       cin>>n>>k;
       for(i=0;i<n;i++)
           cin>>arr[i];
       int low = k;
       int high = n;
       int ans = low;
       while(low<=high)
       {
           int mid=(low+high)/2;
           if(check(mid))
           {
               ans = mid;
               low=mid+1;
           }
           else
               high = mid-1;
       }
       cout<<ans<<"\n";
   }
}
