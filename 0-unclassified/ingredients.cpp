#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[N], dp[1 << N], n, m; 
vector<int> dis[1 << N];

int get(int l, int r) {
  return a[r] - (l? a[l - 1] : 0);
}

int find(int mask) {
  if(mask == 0) return 0;
  if(dp[mask] != -1) return dp[mask];
  int cnt = __builtin_popcount(mask);
  int& ret = dp[mask] = get(0, cnt - 1);
  for(auto it : dis[mask]) {
    int c = __builtin_popcount(it);
    ret = min(ret, find(mask ^ it) + get(cnt - c + 1, cnt - 1));
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i < (1 << n); i++) {
      dp[i] = -1;
      dis[i].clear();
    }
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    for(int i = 1; i < n; i++) {
      a[i] += a[i - 1];
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
      int c, mask = 0;
      scanf("%d", &c);
      for(int j = 0; j < c; j++) {
        int num;
        scanf("%d", &num);
        mask |= (1 << (num - 1));
      }
      for(int now = mask; now < (1 << n); now = ((now + 1) | mask)) {
        dis[now].push_back(mask);
      }
    }
    printf("%d\n", find((1 << n) - 1));
  }
  return 0;
}
