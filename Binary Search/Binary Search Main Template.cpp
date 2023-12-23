#include<bits/stdc++.h>

using namespace std;

//------------------Definition --------------//

#define ll unsigned long long int
#define fn() for(ll i=1;i<=n;i++)
#define actionbeam cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);

int n;
int arr[100000];

bool check(ll mid) {
    // Your implementation of the check function goes here
    // It should return true if the condition is true, false otherwise
}

int main() {
    actionbeam

    ll t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        
        vector<ll> arr(n);
        
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        ll lo = 0;
        ll hi = n - 1;
        ll ans = 0;
        
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            
            if (check(mid)) {
                lo = mid + 1;
            } else {
                ans = mid;
                hi = mid - 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
