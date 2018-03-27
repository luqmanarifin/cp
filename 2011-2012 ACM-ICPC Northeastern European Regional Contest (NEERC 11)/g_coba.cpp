#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const string NAME = "template";
const int N = 1005;

map<long long, int> d;
long long v[N];

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  
  for (int n = 2; n <= 40; n++) {
    int ans = 0;
    d.clear();
    queue<long long> q;
    long long all = (1LL << n) - 1;
    q.push(all);
    d[all] = 0;
    while (!q.empty()) {
      long long now = q.front();
      q.pop();
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) v[j] = 0;
        for (int j = 1; j <= n; j++) {
          if (now & (1LL << (j - 1))) {
            int g = __gcd(j, i);
            v[g] |= (1LL << (j - 1));
          }
        }
        for (int j = 1; j <= n; j++) {
          if (v[j]) {
            long long cur = v[j];
            if (!d.count(cur)) {
              d[cur] = d[now] + 1;
              q.push(cur);
            }
          }
        }
      }
    }
    int p = -1;
    for (int i = 1; i <= n; i++) {
      if (ans < d[(1LL << (i - 1))]) {
        p = i;
        ans = d[(1LL << (i - 1))];
      }
    }
    printf("%d: %d: %d\n", n, p, ans);
  }

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}
