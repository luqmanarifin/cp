#include <bits/stdc++.h>

using namespace std;

int win[105], a[105];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int p = 0;
    for(int i = 1; i < n; i++) {
      if(a[i] > a[p]) p = i;
    }
    win[p]++;
  }
  int ans = 0;
  for(int i = 1; i < n; i++) {
    if(win[i] > win[ans]) ans = i;
  }
  cout << ans + 1 << endl;
  return 0;
}
