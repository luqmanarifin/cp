#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int sum, n;
    scanf("%d %d", &sum, &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    int m = n - 1, nice = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      while(nice < m && a[i] > 1) {
        //printf("%d %d\n", nice, m);
        a[i]--;
        ans++;
        nice++;
      }
      if(nice < m) nice++, ans++;
      m--;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
