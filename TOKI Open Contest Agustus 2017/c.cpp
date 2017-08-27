#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
vector<int> at[N];
int to[N][20];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    at[a[i]].push_back(i);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 20; j++) {
      to[i][j] = N;
    }
  }
  for (int i = n; i >= 1; i--) {
    int p = lower_bound(at[a[i]+1].begin(), at[a[i]+1].end(), i) - at[a[i]+1].begin();
    if (p < at[a[i]+1].size()) {
      to[i][0] = at[a[i]+1][p];
    } else {
      to[i][0] = N;
    }
    int now = to[i][0];
    for (int j = 1; j < 20 && now < N; j++) {
      to[i][j] = to[to[i][j-1]][j-1];
      now = to[i][j];
    }
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int p = lower_bound(at[1].begin(), at[1].end(), l) - at[1].begin();
    int ans = 0;
    if (p < at[1].size() && at[1][p] <= r) {
      ans++;
      int now = at[1][p];
      while (now <= r) {
        p = -1;
        for (int i = 0; i < 20; i++) {
          if (to[now][i] <= r) {
            p = i;
          } else {
            break;
          }
        }
        if (p == -1) break;
        ans += (1 << p);
        now = to[now][p];
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
