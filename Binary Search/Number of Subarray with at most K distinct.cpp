#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll freq[1000001];
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
            cin >> arr[i], freq[arr[i]] = 0;
        ll ans = 0;
        ll start = 0;
        ll current = 0;
        ll currSum = 0;
        while (current < n)
        {
            freq[arr[current]]++;
            if (freq[arr[current]] == 1)
                currSum++;
            while (start <= current and currSum > k)
            {
                if (freq[arr[start]] == 1)
                    currSum--;
                freq[arr[start]]--;
                start++;
            }
            ans += (current - start + 1);
            current++;
        }
        cout << ans << "\n";
    }
}
