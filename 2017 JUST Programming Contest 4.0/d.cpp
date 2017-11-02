#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int cnt[N][26];

char s[N];

int get(int l, int r, int c) {
  return cnt[r][c] - (l? cnt[l - 1][c] : 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d %s", &n, &q, s);
    
    memset(cnt, 0, sizeof(cnt));
    cnt[0][s[0] - 'a']++;
    for (int i = 1; i < n; i++) {
      cnt[i][s[i] - 'a']++;
      for (int j = 0; j < 26; j++) cnt[i][j] += cnt[i - 1][j];
    }
    while (q--) {
      int l, r;
      char c;
      scanf("%d %d %c", &l, &r, &c);
      l--; r--;
      if (l / n == r / n) {
        printf("%d\n", get(l % n, r % n, c - 'a'));
      } else {
        long long ans = get(l % n, n - 1, c - 'a') + get(0, r % n, c - 'a');
        if (l / n + 1 < r / n) {
          ans += 1LL * (r / n - l / n - 1) * get(0, n - 1, c - 'a');
        }
        printf("%lld\n", ans);
      }
    }
  }
  
  return 0;
}
