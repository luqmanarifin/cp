#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N][5];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool ada = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int k = 0; k < n; k++) {
        if (i == k || j == k) continue;
        int cur = 0;
        for (int l = 0; l < 5; l++) {
          cur += (a[j][l] - a[i][l]) * (a[k][l] - a[i][l]);
        }
        if (cur > 0) {
          ada = 1;
          goto COK;
        }
      }
    }
    COK:;
    if (!ada) {
      ans.push_back(i + 1);
    }
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it);
  return 0;
}