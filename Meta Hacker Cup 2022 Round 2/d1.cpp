#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int sum[5][N], n;
int a[N];

void add(int j, int i, int val) {
  for (; i <= n; i |= i + 1) {
    sum[j][i] += val;
  }
}

int find(int j, int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret += sum[j][i];
  }
  return ret;
}

int find(int j, int l, int r) {
  return find(j, r) - find(j, l - 1);
}

int compute(tuple<int, int, int> p) {
  int x, y, z;
  tie(x, y, z) = p;
  return x + 2 * y + 3 * z;
}

int solve(int lef_1, int lef_2, int lef_3, int rig_1, int rig_2, int rig_3, int dif) {
  // printf("solve %d %d %d - %d %d %d - %d\n", lef_1, lef_2, lef_3, rig_1, rig_2, rig_3, dif);
  if (dif % 2) return -1;
  dif /= 2;
  int ans = 0;
  {
    // swap 1 - 3
    int use = min(dif / 2, min(lef_1, rig_3));
    dif -= 2 * use;
    lef_1 -= use;
    lef_3 += use;
    rig_1 += use;
    rig_3 -= use;
    ans += use;
  }
  {
    // swap 1 - 2
    int use = min(dif, min(lef_1, rig_2));
    dif -= use;
    lef_1 -= use;
    lef_2 += use;
    rig_1 += use;
    rig_2 -= use;
    ans += use;
  }
  {
    // swap 2 - 3
    int use = min(dif, min(lef_2, rig_3));
    dif -= use;
    lef_2 -= use;
    lef_3 += use;
    rig_2 += use;
    rig_3 -= use;
    ans += use;
  }
  if (dif > 0) return -1;
  assert(compute(make_tuple(lef_1, lef_2, lef_3)) == compute(make_tuple(rig_1, rig_2, rig_3)));
  return ans; 
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(sum, 0, sizeof(sum));

    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      add(a[i], i, 1);
    }
    long long ans = 0;
    while (m--) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      add(a[x], x, -1);
      a[x] = y;
      add(a[x], x, +1);

      auto lef = make_tuple(find(1, 1, z), find(2, 1, z), find(3, 1, z));
      auto rig = make_tuple(find(1, z+1, n), find(2, z+1, n), find(3, z+1, n));
      if (compute(lef) > compute(rig)) {
        swap(lef, rig);
      }
      int dif = compute(rig) - compute(lef);
      ans += (long long) solve(get<0>(lef), get<1>(lef), get<2>(lef), get<0>(rig), get<1>(rig), get<2>(rig), dif);
    }
    printf("Case #%d: %lld\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
