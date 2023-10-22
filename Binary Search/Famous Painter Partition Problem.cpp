#include<bits/stdc++.h>
using namespace std;
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int

lli n,k;
lli arr[100100];
lli check(lli x){
    lli num_painter_spawned = 0;
    lli last_painter_time_left = 0;
    for(lli i=0;i<n;i++){
        if(arr[i]<=last_painter_time_left){
            last_painter_time_left -= arr[i];
        }else{
            num_painter_spawned++;
            last_painter_time_left = x;
            if(arr[i]<=last_painter_time_left){
                last_painter_time_left -= arr[i];
            }else{
                return 0;
            }
        }
    }
    if(num_painter_spawned <= k)return 1;
    else return 0;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    int t;cin>>t;while(t--){
    cin>>n>>k;
    long long sum = 0;
    lli low= INT_MIN;
    for(lli i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        low=max(low,arr[i]);
    }
    // binary search on answer
    lli lo=low, ans=0;
    long long hi=sum;
    while(lo<=hi){
        lli mid = (lo+hi)/2;
        if(check(mid)==1){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
}
}
