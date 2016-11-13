#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, k;
int lims[N];

int calc() {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      assert(a[i] <= a[j]);
      ret += a[j] - a[i];
    }
  }
  return ret;
}

int dfs(int now, int s, int start) {
  //printf("%d %d %d\n", now, s, start);
  if (now == n) {
    if (s == 0 && calc() == k) {
      for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
      return 1;
    }
    return 0;
  }
  for (int i = start; s - i >= 0; i++) {
    a[now] = i;
    if (dfs(now + 1, s - i, i)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int s;
    scanf("%d %d %d", &n, &s, &k);
    if (dfs(0, s, 0) == 0) {
      puts("-1");
    }
    cerr << tt << " done!" << endl;
  }
  return 0;
}
