#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n,s;
int check(ll mid)
{
    ll temp=mid;
    ll sumofDigit=0;
    while(temp>0)
    {
        sumofDigit+=temp%10;
        temp/=10;
    }
    return mid-sumofDigit>=s;
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
        cin>>n>>s;
        ll low=1;
        ll high=n;
        ll ans=0;
        while(low<=high)
        {
            ll mid=low+(high-low)/2; // Update mid inside the loop
            if(check(mid))
            {
                high=mid-1; 
// Update low, not high
            }
            else
            {
                ans=mid;
                low=mid+1; 
// Update high, not low
            }
        }
        cout<<n-ans<<'\n';
    }
}
