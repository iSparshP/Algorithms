#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> v1(n), v2(n), v3(n);
        ll i, cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> v1[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> v2[i];
        }
        for (int i = 0; i < n; ++i)
        {
            v3[i] = v1[i] - v2[i];
        }
        sort(v3.begin(), v3.end());
        for (int i = 0; i < n; ++i)
        {
            if (v3[i] <= 0)
            {
                if (lower_bound(v3.begin(), v3.end(), -v3[i] + 1ll) - v3.begin() != n)
                {
                    cnt += n - (lower_bound(v3.begin(), v3.end(), -v3[i] + 1ll) - v3.begin());
                }
            }
            else
            {
                cnt += n - (i + 1);
            }
        }
        cout << cnt << endl;
    }
}
 
