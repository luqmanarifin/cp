#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", b + i);
  }
  vector<pair<int,int>> ans;
  int j = 0;
  for(int i = 0; i < n; ) {
    while(a[i] != b[j]) {
      j++;
    }
    int l = 0, r = min(k - 1, n - i - 1);
    while(l < r) {
      int mid = (l + r + 1) >> 1;
      if(a[i + mid] == b[j + mid]) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    ans.emplace_back(i, i + l);
    i += l + 1;
    j += l + 1;
  }
  printf("%d\n", ans.size());
  for(auto it : ans) {
    printf("%d ", it.second - it.first + 1);
    for(int i = it.first; i <= it.second; i++) {
      printf("%d ", i + 1);
    }
    printf("\n");
  }
  return 0;
}
