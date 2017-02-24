#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int til[N];
vector<int> a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v;
      scanf("%d", &v);
      a[i].push_back(v);
    }
  }
  for (int i = 0; i < n; i++) til[i] = i;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      int k = i;
      while (k + 1 < n && a[k][j] <= a[k + 1][j]) k++;
      for (int it = i; it <= k; it++) {
        til[it] = max(til[it], k);
      }
      i = k;
    }
  }
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    puts(til[l] >= r? "Yes": "No");
  }

  return 0;
}
