#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);;
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll prev[26];
        for(ll i=0;i<26;i++)
            prev[i] = -1;
        long long ans = 26*((n*(n+1))/2);
        for(ll i=0;i<n;i++){
            ll lenNotWithChar = i - prev[s[i]-'a']-1;
            ans = ans - ((lenNotWithChar*(lenNotWithChar+1))/2);
            prev[s[i]-'a'] = i;
        }
        for(ll i=0;i<26;i++){
            ll lenNotWithChar = n - prev[i]-1;
            ans = ans - ((lenNotWithChar*(lenNotWithChar+1))/2);
        }
        cout<<ans<<"\n";
    }

}
