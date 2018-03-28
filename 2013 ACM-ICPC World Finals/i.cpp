#include <bits/stdc++.h>

using namespace std;

const int N = 505, inf = 1e9 +7;

long long calc(long long ab, long long mn, long long val) {
  long long le = 0, ri = 1e12;
  if (val <= 0) return 0;
  while (le < ri) {
    long long mid = (le + ri + 1) / 2;
    long long v = mid * ab;
    long long atap = val + (v + mn - 1) / (mn);
    if (mid < atap)
      le = mid;
    else
      ri = mid - 1;
  }
  return ab * le;
}
int d[N][N], n, m, a, b, f[N], g[N];
int mi[N][N], le[N];

int main() {
  scanf("%d %d %d %d", &a, &b, &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      scanf("%d", d[i]+j); 
  }
  long long ans = 0;
  for (int it = 0; it < 2; ++it) {
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        mi[i][j] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= m; ++j)
        f[j] = inf, g[j] = 0;
      for (int j = i; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
          f[k] = min(f[k], d[j][k]);
        }
        for (int k = 0; k <= m; ++k)
          g[k] = 0;
        stack<int> st;
        for (int k = 0; k < m; ++k) {
          while (!st.empty() && f[st.top()] >= f[k]) st.pop();
          le[k] = st.empty() ? 0 : st.top() + 1;
          st.push(k);
        }
        while (!st.empty()) st.pop();
        for (int k = m-1; k >= 0; --k) {
          while (!st.empty() && f[st.top()] >= f[k]) st.pop();
          int ri = st.empty() ? m-1 : st.top() - 1;
          g[ri - le[k] + 1] = max(g[ri - le[k] + 1], f[k]);
          st.push(k);
        }
        int len = j - i + 1;
        for (int k = m; k > 0; --k) {
          g[k-1] = max(g[k-1], g[k]);
          mi[len][k] = max(mi[len][k], g[k]);
        }
      }
    }
    for (int i = 1; i <= a; ++i) {
      for (int j = 1; j <= b; ++j) {
        ans = max(ans, calc(i*j, n*m, mi[i][j]));
      }
    }
    swap(a, b);
  }
  cout << ans << endl;
  return 0;
}