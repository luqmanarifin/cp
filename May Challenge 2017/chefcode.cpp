#include <bits/stdc++.h>

using namespace std;

const int N = 50;
const long long inf = 3e18;

map<long long, int> vis[N];
long long a[N], k, all[N];
int n, ans;

int dfs(int i, long long now) {
  if (i == n) return 0;
  if (vis[i].count(now)) return vis[i][now];
  if (now < inf / all[i] && now * all[i] <= k) {
    //printf("%d %lld: %d\n", i, now, 0);
    return vis[i][now] = 0;
  }
  if (now >= inf / a[i] || now * a[i] > k) {
    //printf("%d %lld: %d\n", i, now, (1 << (n - i)) - 1);
    return vis[i][now] = (1 << (n - i)) - 1;
  }
  int ret = dfs(i + 1, now) + dfs(i + 1, now * a[i]);
  //printf("%d %lld: %d\n", i, now, ret);
  return vis[i][now] = ret;
}

int main() {
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  sort(a, a + n);
  all[n - 1] = a[n - 1]; 
  for (int i = n - 2; i >= 0; i--) {
    long long lim = inf / all[i + 1];
    if (a[i] > lim) {
      all[i] = inf;
    } else {
      all[i] = a[i] * all[i + 1];
    }
  }
  cout << (1 << n) - 1 - dfs(0, 1) << endl;
  return 0;
}
