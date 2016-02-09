#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    int now = 0;
    for(int i = 0; i < n; i++) {
      int j = i + 1;
      while(abs(a[j] - a[j - 1]) <= k && j < n) j++;
      now++;
      i = j - 1;
    }
    printf("Case #%d: %d\n", tt, now);
  }
  
  return 0;
}
