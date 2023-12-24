#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define N 1000005
 
int a[N], b[N];
 
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        // take a as smaller array
        if(n > m) {
            swap(a, b);
            swap(n, m);
        }
        sort(a,a+n);
        sort(b,b+m);
        int l = a[0] + b[0], r = a[n-1] + b[m-1];
        int ans = a[0] + b[0];
        while(l <= r) {
            int mid = (l + r)/2;
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                int x = upper_bound(b, b+m, mid - a[i]) - b;
                cur += x;
            }
            if(cur >= k) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
