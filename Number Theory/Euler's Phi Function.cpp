#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    ll ans = n;

    for(ll i = 2; i * i <= n; i++) {
        bool is = false;
        while(n % i == 0) {
            n /= i;
            is = true;
        }
        if(is) {
            ans /= i;
            ans *= (i - 1);
        }
    }

    if(n > 1) {
        ans /= n;
        ans *= (n - 1);
    }

    cout << ans << "\n";
}
