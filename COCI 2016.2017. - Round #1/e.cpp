#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int inf = 2e9;

int to[N];
set<int> comp[N];
int bef[2 * N], aft[2 * N], who[N];

set<pair<int, int>> cutest, all;

int a[N], p[N], v[N], n;

int get_cutest(int id_comp) {
  int lower = p[to[id_comp]];
  auto it = comp[id_comp].lower_bound(lower);
  if (it != comp[id_comp].end()) {
    return *it;
  } else {
    return inf;
  }
}

// merge comp u -> v
void merge(int u, int v) {
  int cutest_u = get_cutest(u);
  int cutest_v = get_cutest(v);
  cutest.erase({cutest_u, u});
  cutest.erase({cutest_v, v});
  if (comp[u].size() < comp[v].size()) {
    for (auto it : comp[u]) {
      comp[v].insert(it);
    }
    auto it = comp[v].lower_bound(p[to[v]]);
    if (it != comp[v].end()) cutest.insert({*it, v});
  } else {
    for (auto it : comp[v]) {
      comp[u].insert(it);
    }
    to[u] = to[v];
    who[to[u]] = u;
    auto it = comp[u].lower_bound(p[to[u]]);
    if (it != comp[u].end()) cutest.insert({*it, u});
  }
  
}

// value - id_comp
void remove_asal(pair<int, int> val) {
  cutest.erase(val);
  all.erase(val);
} 

void remove(int at) {
  int behind = bef[at];
  int front = aft[at];
  if (behind >= 0) aft[behind] = front;
  if (front >= 0) bef[front] = behind;
}

void remove_sasaran(int at) {
  remove(at);
  remove(at + n);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  for (int i = 0; i < n; i++) scanf("%d", v + i);
  for (int i = 0; i < n; i++) {
    to[i] = i;
    who[i] = i;
    comp[a[i]].insert(v[i]);
    if (v[i] > p[a[i]]) {
      cutest.insert({v[i], a[i]});
    }
    all.insert({v[i], a[i]});
  }
  for (int i = 0; i < n; i++) for (auto it : comp[i]) printf("%d di %d\n", it, i);
  for (int i = 0; i < 2 * N; i++) {
    bef[i] = i - 1;
    aft[i] = i + 1;
  }
  int ans = 0;
  for (int tt = 0; tt < n; tt++) {
    if (cutest.empty()) {
      auto it = all.begin();
      printf("terpaksa %d %d\n", it->first, it->second);
      remove_asal(*it);
      remove_sasaran(it->second);
      merge(it->second, who[aft[to[it->second]] % n]);
    } else {
      ans++;
      auto it = cutest.begin();
      printf("cute %d %d\n", it->first, it->second);
      remove_asal(*it);
      remove_sasaran(it->second);
      merge(it->second, who[aft[to[it->second]] % n]);
    }
  }
  cout << ans << endl;
  return 0;
}
