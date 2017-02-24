#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) {
    int v;
    scanf("%d", &v);
    vector<int> num;
    while (v--) {
      int l;
      scanf("%d", &l);
      num.push_back(l);
    }
    bool ada = 0;
    for (auto it : num) if (a[it] == 0) ada = 1;
    if (ada) {
      for (auto it : num) a[it] ^= 1;
    }
  }
  int ada = 0;
  for (int i = 1; i <= n; i++) if (a[i] == 0) ada = 1;
  if (ada) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}