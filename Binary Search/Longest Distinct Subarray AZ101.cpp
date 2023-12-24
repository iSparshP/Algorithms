#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int l = 0;
        int ans = 0;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            while(m[a[i]] == 1) {
                m[a[l]]--;
                l++;
            }
            m[a[i]]++;
            ans = max(ans, i-l+1);
        }
        cout << ans << "\n";
    }
    return 0;
}
