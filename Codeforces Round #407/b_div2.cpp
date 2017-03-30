#include <bits/stdc++.h>

using namespace std;

long long b1, q, l, m;

map<long long, bool> bad, done;

int main() {
  scanf("%I64d %I64d %I64d %I64d", &b1, &q, &l, &m);
  for (int i = 0; i < m; i++) {
    long long v;
    scanf("%I64d", &v);
    bad[v] = 1;
  }
  long long now = b1;
  while (abs(now) <= l) {
    if (done[now]) {
      long long temp = now;
      do {
        if (!bad[now]) {
          puts("inf");
          return 0;
        }
        now *= q;
      } while (now != temp);
      int ans = 0;
      for (auto it : done) if (!bad[it.first]) ans++;
      cout << ans << endl;
      return 0;
    }
    done[now] = 1;
    now *= q;
  }
  int ans = 0;
  for (auto it : done) if (!bad[it.first]) ans++;
  cout << ans << endl;
  return 0;
}
