#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int BIT = 20;
const int MAX_NUM = (1 << BIT);

int a[N], sum[N], n;
vector<int> pos[MAX_NUM][2];

int solve(int bit) {
  for (int i = 0; i < MAX_NUM; i++) {
    pos[i][0].clear();
    pos[i][1].clear();
  }
  int offset = (-1 ^ ((1 << (bit + 1)) - 1));
  for (int i = 1; i <= n; i++) {
    sum[i] = (a[i] & offset);
    sum[i] ^= sum[i-1];
    pos[sum[i]][i % 2].push_back(i);
  }
  int until = 0, ret = 0;
  for (int i = 1; i <= n; i++) {
    if ((a[i] & (1 << bit)) == 0) continue;
    if (until < i) {
      until = i;
      while (until + 1 <= n && (a[until + 1] & (1 << bit))) {
        until++;
      }
    }
    int c = (i % 2) ^ 1;
    int idx = lower_bound(pos[sum[i-1]][c].begin(), pos[sum[i-1]][c].end(), until + 1) - pos[sum[i-1]][c].begin();
    if (idx > 0) {
      int best = pos[sum[i-1]][c][idx-1];
      if (best > i) {
        ret = max(ret, best - i + 1);
      }
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for (int i = 0; i < BIT; i++) {
    ans = max(ans, solve(i));
  }
  cout << ans << endl;
  return 0;
}
