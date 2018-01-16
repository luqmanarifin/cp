#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17);

int* q[1 << 20];
int len[1 << 20], pt;

long long cnt[1 << 18];
int h[1 << 18];
int x[(1 << 18) + 5], y[(1 << 18) + 5];
int now;

int ans[(1 << 18) + 5];

void solve(int l, int r, int at) {
  if (len[at] == 0) return;
  if (l == r) {
    ans[l] += len[at];
    return;
  }
  int mid = (l + r + 1) >> 1;
  int lef = pt++;
  int rig = pt++;
  q[lef] = new int[len[at]];
  q[rig] = new int[len[at]];
  while (now < mid) {
    ++now;
    cnt[x[now]] += y[now];
  }
  while (now > mid) {
    cnt[x[now]] -= y[now];
    --now;
  }
  for (int i = 0; i < len[at]; i++) {
    long long cur = 0;
    int j = q[at][i];
    for (int mask = j; mask < N; mask = ((mask + 1) | j)) {
      cur += cnt[mask];
      if (cur >= h[j]) break;
    }
    if (cur >= h[j]) {
      q[lef][len[lef]++] = j;
    } else {
      q[rig][len[rig]++] = j;
    }
  }
  solve(l, mid - 1, lef);
  solve(mid, r, rig);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", h + i);
  int que;
  scanf("%d", &que);
  for (int i = 1; i <= que; i++) {
    scanf("%d %d", x + i, y + i);
    x[i] &= (N - 1);
  }
  
  q[0] = new int[n];
  len[0] = n;
  for (int i = 0; i < n; i++) q[0][i] = i;
  pt++;
  
  solve(0, que, 0);
  for (int i = que; i >= 1; i--) ans[i - 1] += ans[i];
  for (int i = 1; i <= que; i++) printf("%d\n", ans[i]);
  return 0;
}
