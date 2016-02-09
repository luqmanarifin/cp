#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char a[N], b[N], ans[N];

int main() {
  int n, t;
  scanf("%d %d %s %s", &n, &t, a, b);
  t = n - t;
  int na = t, nb = t;
  for(int i = 0; i < n; i++) {
    if(a[i] == b[i] && na && nb) {
      ans[i] = a[i];
      na--;
      nb--;
    }
  }
  for(int i = 0; i < n; i++) {
    if(ans[i] == 0 && na && a[i] != b[i]) {
      ans[i] = a[i];
      na--;
    }
  }
  for(int i = 0; i < n; i++) {
    if(ans[i] == 0 && nb && a[i] != b[i]) {
      ans[i] = b[i];
      nb--;
    }
  }
  for(int i = 0; i < n; i++) {
    if(ans[i] == 0) {
      ans[i] = a[i];
      while(ans[i] == a[i] || ans[i] == b[i]) {
        if(ans[i] == 'z') ans[i] = 'a';
        else ans[i]++;
      }
    }
  }
  if(na || nb) {
    puts("-1");
    return 0;
  }
  printf("%s\n", ans);
  return 0;
}
