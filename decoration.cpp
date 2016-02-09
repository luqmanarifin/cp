#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char a[N], b[N];
int l[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    
    int n;
    scanf("%d %s %s", &n, a + 1, b + 1);
    l[1] = 1;
    for(int i = 2; i <= n; i++) {
      if(b[i] == b[i - 1]) {
        l[i] = l[i - 1];
      } else {
        l[i] = l[i - 1] + 1;
      }
    }
    r[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
      if(b[i] == b[i + 1]) {
        r[i] = r[i + 1];
      } else {
        r[i] = r[i + 1] + 1;
      }
    }
    for(int i = 1; i <= n; i++) {
      if(a[i] == b[i]) {
        l[i] = 0;
      } else {
        break;
      }
    }
    for(int i = n; i >= 1; i--) {
      if(a[i] == b[i]) {
        r[i] = 0;
      } else {
        break;
      }
    }
    /*
    for(int i = 1; i <= n; i++) {
      printf("%d ", l[i]);
    }
    printf("\n");
    for(int i = 1; i <= n; i++) {
      printf("%d ", r[i]);
    }
    printf("\n");
    */
    int ans = min(r[1], l[n]);
    for(int i = 1; i <= n; ) {
      int j = i;
      while(j <= n && a[j] == b[j]) j++;
      if(i == j && a[i] != b[i]) {
        ans = min(ans, max(l[i], r[i + 1]));
      } else {
        ans = min(ans, max(l[i - 1], r[j + 1]));
      }
      i = j + 1;
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }
  
  return 0;
}
