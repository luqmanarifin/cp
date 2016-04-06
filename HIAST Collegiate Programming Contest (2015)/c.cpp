#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, p;
    scanf("%d %d %s", &n, &p, s);
    p--;
    int ans = 0;
    if(p < n / 2) {
      int mn = p, mk = p;
      for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n - 1 - i]) {
          mn = min(mn, i);
          mk = max(mk, i);
          int dif = abs(s[i] - s[n - 1 - i]);
          dif = min(dif, 26 - dif);
          ans += dif;
          //printf("masuk %d\n", i);
        }
      }
      //cout << ans << endl;
      int add = min(2*mk - p - mn, mk + p - 2*mn);
      //cout << add << endl;
      ans += add;
    } else {
      int mn = p, mk = p;
      for(int i = n / 2; i < n; i++) {
        if(s[i] != s[n - 1 - i]) {
          mn = min(mn, i);
          mk = max(mk, i);
          int dif = abs(s[i] - s[n - 1 - i]);
          dif = min(dif, 26 - dif);
          ans += dif;
        }
      }
      ans += min(2*mk - p - mn, mk + p - 2*mn);
    }
    printf("%d\n", ans);
  }
  
  return 0;
}