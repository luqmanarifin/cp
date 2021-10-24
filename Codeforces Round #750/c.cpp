#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

char s[N];
int cnt[N];

void clear(int n) {
  for (int i = 0; i <= n; i++) cnt[i] = 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    int ans = inf;
    for (int z = 0; z < 26; z++) {
      clear(n);
      int idx = 0;
      vector<char> v;
      for (int i = 0; i < n; i++) {
        if (z + 'a' == s[i]) {
          cnt[idx]++;
        } else {
          idx++;
          v.push_back(s[i]);
        }
      }
      bool palin = 1;
      for (int i = 0; i < v.size(); i++) {
        int r = v.size() - 1 - i;
        if (v[i] != v[r]) palin = 0;
      }
      if (!palin) continue;
      int cur = 0;
      for (int i = 0; i < (idx + 1) / 2; i++) {
        int l = i;
        int r = idx - i;
        int rem = max(cnt[l], cnt[r]) - min(cnt[l], cnt[r]);
        cur += rem;
      }
      ans = min(ans, cur);
      // if (cur == 2) printf("huruf %c\n", z + 'a');
    }
    if (ans == inf) ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}
