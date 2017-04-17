#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];
vector<int> edge[N];

int main() {
  int n;
  scanf("%d", &n);
  int maxi = -2e9, cnt_max = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] > maxi) {
      maxi = a[i];
      cnt_max = 1;
    } else if (a[i] == maxi) {
      cnt_max++;
    }
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int cnt_min = 0;
  for (int i = 1; i <= n; i++) if (a[i] == maxi - 1) cnt_min++;
  if (cnt_max == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i] != maxi) continue;
      int near = 0;
      for (auto it : edge[i]) {
        if (a[it] == maxi - 1) {
          near++;
        }
      }
      if (near == cnt_min) {
        printf("%d\n", maxi);
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int near = (a[i] == maxi? 1 : 0);
    for (auto it : edge[i]) {
      if (a[it] == maxi) near++;
    }
    if (near == cnt_max) {
      printf("%d\n", maxi + 1);
      return 0;
    }
  }
  printf("%d\n", maxi + 2);
  return 0;
}
