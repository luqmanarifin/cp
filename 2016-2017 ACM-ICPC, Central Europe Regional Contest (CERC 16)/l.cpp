#include <bits/stdc++.h>

using namespace std;

const int N = 550;

int a[N][3];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", a[j]+i);
    }
  }
  set<int> zero, one, st[3];
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 0; j < 3; ++j)
      cnt += a[i][j];
    if (cnt == 0)
      zero.insert(i);
    else if (cnt == 3)
      one.insert(i);
    else if (cnt == 1) {
      for (int j = 0; j < 3; ++j) {
        if (a[i][j] == 1)
          st[j].insert(i);
      }
    }
    else {
      for (int j = 0; j < 3; ++j) {
        if (a[i][j] == 0)
          st[j].insert(-i);
      }
    }
  }
  int cnt = 0;
  for (int j = 0; j < 3; ++j)
    cnt += st[j].size() > 0;
  //~ cerr << cnt <<endl;
  if (cnt != 2) {
    puts("-1");
    return 0;
  }
  vector<pair<int, int> > ans;
  int x, y;
  if (st[0].empty())
    x = 1, y = 2;
  else if (st[1].empty())
    x = 0, y = 2;
  else
    x = 0, y = 1;
  for (int u : zero) {
    ans.emplace_back(u, -u);
  }
  for (int u : one) {
    ans.emplace_back(-u, u);
  }
  int u = *st[x].begin(), v = *st[y].begin();
  for (int z : st[x]) {
    if (u == z) continue;
    ans.emplace_back(u, z);
    ans.emplace_back(z, u);
  }
  for (int z : st[y]) {
    if (v == z) continue;
    ans.emplace_back(v, z);
    ans.emplace_back(z, v);
  }
  ans.emplace_back(u, -v);
  printf("%d\n",(int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    int p = ans[i].first, q = ans[i].second;
    if (p < 0)
      printf("!x%d -> ", -p);
    else
      printf("x%d -> ", p);
    if (q < 0)
      printf("!x%d\n", -q);
    else
      printf("x%d\n", q);
  }
  return 0;
}
