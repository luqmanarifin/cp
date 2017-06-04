#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const long long mod = 2e9 + 89;
const int BIG = 1e6 + 5;

vector<int> edge[N];
set<int> all[N];

int h[N], dad[N];
long long val[N];
bool ok[N];

vector<int> p;
bool is[BIG];

void dfs(int now, int bef) {
  bool leaf = 1;
  for (auto it : edge[now]) {
    if (it == bef || !ok[it]) continue;
    leaf = 0;
    dfs(it, now);
  }
  if (leaf) {
    h[now] = 0;
    val[now] = 1;
    return;
  }
  h[now] = 0;
  val[now] = 0;
  for (auto it : edge[now]) {
    if (it == bef || !ok[it]) continue;
    h[now] = max(h[now], h[it] + 1);
    val[now] += val[it];
    val[now] %= mod;
  }
  val[now] *= p[h[now]];
  val[now] %= mod;
}

int count(int now, int bef) {
  int ret = 1;
  for (auto it : edge[now]) {
    if (it == bef || !ok[it]) continue;
    ret += count(it, now);
  }
  return ret;
}

int far(int now, int bef = -1) {
  dad[now] = bef;
  h[now] = (bef == -1? 0 : h[bef] + 1);
  int ret = now;
  for (auto it : edge[now]) {
    if (it == bef || !ok[it]) continue;
    int cur = far(it, now);
    if (h[ret] < h[cur]) {
      ret = cur;
    }
  }
  return ret;
}

int main() {
  for (int i = 2; i < BIG; i++) {
    if (!is[i]) {
      if (i > N) {
        p.push_back(i);
      }
      for (long long j = 1LL * i * i; j < BIG; j += i) {
        assert(j >= 0);
        is[j] = 1;
      }
    }
  }
  srand(time(0));
  int shuffle = rand() % 10;
  while (shuffle--) random_shuffle(p.begin(), p.end());
  
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    memset(ok, 0, sizeof(ok));
    for (int i = 0; i < n; i++) if (mask & (1 << i)) ok[i] = 1;
    bool connected = 0;
    int node = -1;
    for (int i = 0; i < n; i++) if (mask & (1 << i)) {
      if (count(i, -1) == __builtin_popcount(mask)) {
        connected = 1;
      }
      node = i;
      break;
    }
    if (!connected) continue;
    node = far(node);
    node = far(node);
    long long need;
    if (h[node] % 2 == 0) {
      int step = h[node] / 2;
      while (step--) node = dad[node];
      dfs(node, -1);
      need = val[node];
    } else {
      int step = h[node] / 2;
      while (step--) node = dad[node];
      dfs(node, -1);
      need = val[node];
      dfs(dad[node], -1);
      need = min(need, val[dad[node]]);
    }
    all[__builtin_popcount(mask)].insert(need);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += all[i].size();
  cout << ans << endl;
  return 0;
}
