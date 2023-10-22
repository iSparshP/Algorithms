#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n,k;
ll arr[100100];

int check(ll mid)
{
    ll count=1;
    ll previous=arr[0];
    for (int i = 1; i < n; ++i)
    {
        if(arr[i]>= previous+mid){
            count++;
            previous=arr[i];
        }
    }
    return count>=k;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    ll t;cin>>t;
    while(t--)
    {   
        cin>>n>>k;
        for(ll i=0; i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll low=1;
        ll high=arr[n-1]-arr[0];
        ll ans=1;

        while(low<=high)
        {
            ll mid=low+(high-low)/2; // Update mid inside the loop
            if(check(mid))
            {
                ans=mid;
                low=mid+1; // Update low, not high
            }
            else
            {
                high=mid-1; // Update high, not low
            }
        }
        cout<<ans<<'\n';
    }
}
