#include <bits/stdc++.h>

using namespace std;

const int N = 205;

char s[N];
int a[N];
bool vis[N];

long long gcd(long long a, long long b) {
  return b? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(vis, 0, sizeof(vis));

    int n;
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);

    long long ans = 1;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      vis[i] = 1;
      vector<char> c = {s[i]};
      int p = a[i];
      while (p != i) {
        vis[p] = 1;
        c.push_back(s[p]);
        p = a[p];
      }

      int sz = c.size(), elem = c.size();
      for (int f = 1; f <= sz; f++) {
        if (sz % f) continue;
        bool good = 1;
        for (int st = 0; st < f; st++) {
          for (int k = st + f; k < sz; k += f) {
            if (c[k] != c[k - f]) {
              good = 0;
              goto OUT;
            }
          }
        }
        OUT:;
        if (good) {
          elem = f;
          break;
        }
      }
      ans = lcm(ans, elem);
    }
    printf("%lld\n", ans);
  }

  return 0;
}
