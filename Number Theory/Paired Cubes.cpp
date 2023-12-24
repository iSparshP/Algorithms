#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int n; cin >> n;

   map <ll,int> M;

   ll ans = 0;

   for(int i = 0; i < n; i++) {
      int x; cin >> x;
      ll norm = 1;
      ll tar = 1;
      for(int j = 2; j * j <= x; j++) {
         int cnt = 0;
         while(x % j == 0) {
            x /= j;
            cnt++;
         }
         cnt %= 3;
         for(int k = 0; k < cnt; k++) {
            norm *= j;
         }
         if(cnt) {
            for(int k = 0; k < 3 - cnt; k++) {
               tar *= j;
            }
         }
      }
      if(x > 1) {
         norm *= x;
         tar *= (x * x);
      }
      ans += M[tar];
      M[norm]++;
   }

   cout << ans << "\n";
}
