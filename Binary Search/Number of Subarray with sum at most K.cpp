#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcases;
    cin >> testcases;
    while (testcases--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        ll ans = 0;
        ll start = 0;
        ll current = 0;
        ll currSum = 0;
        while (current < n)
        {
            currSum += arr[current];
            while (start <= current and currSum > k)
            {
                currSum -= arr[start];
                start++;
            }
            ans += (current - start + 1);
            current++;
        }
        cout << ans << "\n";
    }
}
