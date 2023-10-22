#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n,k;
ll arr[100100];
int check(ll mid)
{
    ll needed=0;
    ll i=1;
    while(i<n)
    {
        needed+=((arr[i]-arr[i-1]+mid-1)/mid)-1;
        i++;
    }
    return needed<=k;
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
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        ll low=1;
        ll high=1e9;
        ll ans=high;
        while(low<=high)
        {
            ll mid=low+(high-low)/2; // Update mid inside the loop
            if(check(mid))
            {
                ans=mid;
                high=mid-1; 
// Update low, not high
            }
            else
            {
                low=mid+1; 
// Update high, not low
            }
        }
        cout<<ans<<'\n';
    }
}
