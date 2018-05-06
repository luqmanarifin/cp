
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int l, r;
long long cur;
int cnt[N], a[N];

void maju_r() {
  r++;
  cur += cnt[a[r]];
  cnt[a[r]]++;
}

void mundur_r() {
  cnt[a[r]]--;
  cur -= cnt[a[r]];
  r--;
}

void maju_l() {
  cnt[a[l]]--;
  cur -= cnt[a[l]];
  l++;
}

void mundur_l() {
  l--;
  cur += cnt[a[l]];
  cnt[a[l]]++;
}

void cocok(int le, int ri) {
  ri--;
  while (r < ri) maju_r();
  while (le < l) mundur_l();
  while (r > ri) mundur_r();
  while (le > l) maju_l();
}

long long dp[N], v[N];

void solve(int to_lef, int to_rig, int from_lef, int from_rig) {
  if (to_lef > to_rig) return;
  //printf("%d %d: %d %d\n", to_lef, to_rig, from_lef, from_rig);
  if (from_lef == from_rig) {
    for (int i = to_lef; i <= to_rig; i++) {
      cocok(from_lef, i);
      dp[i] = v[from_lef] + cur;
    }
    return;
  }
  int mid = (to_lef + to_rig) >> 1, p = -1;
  dp[mid] = 1e18;
  for (int i = from_lef; i <= from_rig && i < mid; i++) {
    cocok(i, mid);
    long long ncur = v[i] + cur;
    if (ncur < dp[mid]) {
      dp[mid] = ncur;
      p = i;
    }
  }
  solve(to_lef, mid - 1, from_lef, p);
  solve(mid + 1, to_rig, p, from_rig);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  cnt[a[0]]++;
  for (int i = 0; i < n; i++) {
    cocok(0, i + 1);
    dp[i + 1] = cur;
  }
  for (int it = 1; it < k; it++) {
    for (int i = 0; i < N; i++) {
      v[i] = dp[i];
    }
    solve(1, n, 0, n - 1);
  }
  cout << dp[n] << endl;
  return 0;
}
