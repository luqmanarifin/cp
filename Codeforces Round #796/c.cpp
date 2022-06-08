#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

bool done[N];           // M-based
int lef[N], rig[N];     // N-based
vector<int> as_lef[N], as_rig[N]; // N-based
set<int> bad;
vector<int> to_remove;  // index of range

int a[N], b[N];
long long s[N];

void do_removal(int x) {
  if (done[x]) return;
  int l = lef[x], r = rig[x];
  if (s[l - 1] == 0 && s[r] == 0) {
    done[x] = 1;
    to_remove.push_back(x);
  }
}

void remove(int x) {
  for (auto it : as_lef[x]) do_removal(it);
  for (auto it : as_rig[x]) do_removal(it);
  bad.erase(x);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + a[i] - b[i];
    }
    for (int i = 0; i < m; i++) {
      scanf("%d %d", lef + i, rig + i);
      as_lef[lef[i] - 1].push_back(i);
      as_rig[rig[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      if (s[i] != 0) {
        bad.insert(i);
      }
    }
    for (int i = 0; i < m; i++) {
      if (s[lef[i] - 1] == 0 && s[rig[i]] == 0) {
        to_remove.push_back(i);
        done[i] = 1;
      }
    }
    while (!to_remove.empty()) {
      int idx = to_remove.back();
      to_remove.pop_back();
      int l = lef[idx], r = rig[idx];
      vector<int> x;
      auto it = bad.lower_bound(l);
      while (it != bad.end() && *it <= r) {
        x.push_back(*it);
        it++;
      }
      for (auto i : x) s[i] = 0;
      for (auto i : x) {
        remove(i);
      }
    }
    puts(bad.empty()? "YES" : "NO");

    for (int i = 0; i <= m; i++) done[i] = 0;
    for (int i = 0; i <= n; i++) {
      as_lef[i].clear();
      as_rig[i].clear();
    }
    bad.clear();
    to_remove.clear();
  }

  return 0;
}
