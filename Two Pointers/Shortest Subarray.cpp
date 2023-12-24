#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll n;
        cin>>n;
        ll arr[n];
        ll freq[100001] = {0};
        for(ll i=0;i<n;i++)cin>>arr[i],freq[arr[i]]++;
        ll distinctElement = 0;
        for(ll i=0;i<=100000;i++){
            distinctElement+=(freq[i]>0);
            freq[i] = 0;
        }
        ll ans = n;
        ll start = 0;
        ll current = 0;
        ll currSum = 0;
        while(current<n){
            freq[arr[current]]++;
            if(freq[arr[current]]==1)
                currSum++;
            while(start<=current and currSum==distinctElement){
                ans = min(ans,current-start+1);
                if(freq[arr[start]]==1)
                    currSum--;
                freq[arr[start]]--;
                start++;
            }
            current++;
        }
        cout<<ans<<"\n";
    }
}
