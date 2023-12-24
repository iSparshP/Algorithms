#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        ll n, d;
        cin >> n >> d;

        if (!n && !d)
            break;

        map<ll, ll> M;

        for (ll i = 2; i * i <= n; i++)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (cnt)
                M[i] += 2 * cnt;
        }

        if (n > 1)
            M[n] += 2;

        M[2] += 2 * d;
        M[5] += 2 * d;

        ll ans = 1;
        bool sqr = true;

        ll mod = 1000007;

        for (auto it : M)
        {
            ans *= (it.second + 1);
            ans %= mod;
            if (ans < 0)
                ans += mod;
            if (it.second % 2)
                sqr = false;
        }

        ans *= 2;
        ans %= mod;
        if (ans < 0)
            ans += mod;

        if (sqr)
            ans = (ans - 1 + mod) % mod;

        cout << ans << "\n";
    }
}
