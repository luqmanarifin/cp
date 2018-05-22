#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

#define ull unsigned long long

vector<int> to_rig[N], to_lef[N], sum_rig[N];
ull A, B, C;

ull get(int n) {
  if (n == 0) return 0;
  return 1ULL * n * (n - 1) / 2;
}

ull sum(int n) {
  return 1ULL * n * (n + 1) / 2;
}

ull sum(int l, int r) {
  if (l > r) return 0;
  return sum(r) - sum(l - 1);
}

ull ada(int l, int r) {
  if (l > r) return 0;
  return r - l + 1;
}

ull cnt_kanan(int base_lef, int rig) {
  int p = upper_bound(to_rig[base_lef].begin(), to_rig[base_lef].end(), rig) - to_rig[base_lef].begin();
  return to_rig[base_lef].size() - p;
}

ull sum_kanan(int base_lef, int rig) {
  int p = upper_bound(to_rig[base_lef].begin(), to_rig[base_lef].end(), rig) - to_rig[base_lef].begin();
  if (p == to_rig[base_lef].size()) return 0;
  return sum_rig[base_lef][p];
}

int main() {
  int n, m;
  cin >> n >> m;
  cin >> A >> B >> C;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    int l = min(u, v);
    int r = max(u, v);
    to_rig[l].push_back(r);
    to_lef[r].push_back(l);
  }
  for (int i = 1; i <= n; i++) {
    sort(to_rig[i].begin(), to_rig[i].end());
    sum_rig[i].assign(to_rig[i], 0);
    for (int j = (int) sum_rig[i].size() - 1; j >= 0; j--) {
      if (j + 1 < sum_rig.size()) {
        sum_rig[i][j] += sum_rig[i][j + 1];
      }
      sum_rig[i][j] += to_rig[i][j];
    }
  }

  // plus x x x
  ull ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += get(n - i) * A * i;
    ans += 1ULL * (i - 1) * (n - i) * B * i;
    ans += get(i - 1) * C * i;
  }

  // minus 4 x x
  for (int i = 1; i <= n; i++) {
    for (auto it : to_rig[i]) {
      ull cnt = ada(i + 1, it - 1);
      ans -= cnt * A * i;
      ans -= sum(i + 1, it - 1) * B;
      ans -= cnt * C * it;
    }
  }

  // minus 0 1 x
  for (int i = 1; i <= n; i++) {
    for (auto it : to_rig[i]) {
      ull cnt = n - it - cnt_kanan(i, it);
      ans -= cnt * i * A;
      ans -= cnt * it * B;
      ans -= (sum(it + 1, n) - sum_kanan(i, it)) * C;
    }
  }

  // TODO: minus 0 0 2

  cout << ans << endl;
  return 0;
}
