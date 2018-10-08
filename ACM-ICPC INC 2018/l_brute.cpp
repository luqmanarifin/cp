#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int a[100][100];

int solve(vector<int> p) {
  if (p.size() == 1) return 0;
  vector<int> q;
  int add = 0;
  for (int i = 0; i < p.size(); i += 2) {
    if (p[i] == 0) {
      add = a[0][p[i+1]];
    } else if (p[i + 1] == 0) {
      add = a[0][p[i]];
    }
    if (a[p[i]][p[i+1]] > 0) {
      q.push_back(p[i]);
    } else {
      q.push_back(p[i+1]);
    }
  }
  if (add == -1) return inf;
  return add + solve(q);
}

int main() {
  int n;
  scanf("%d", &n);
  int pw = 1;
  while (n--) pw *= 2;
  n = pw;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  vector<int> p;
  for (int i = 0; i < n; i++) p.push_back(i);
  int ans = inf;
  do {
    ans = min(ans, solve(p));
  } while (next_permutation(p.begin(), p.end()));
  if (ans == inf) ans = -1;
  printf("%d\n", ans);
  return 0;
}
