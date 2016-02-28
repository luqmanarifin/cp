#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bef[N], aft[N];
int x[N], y[N];

void del(int i) {
  aft[bef[i]] = aft[i];
  bef[aft[i]] = bef[i];
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i <= n + 1; i++) {
    bef[i] = i - 1;
    aft[i] = i + 1;
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int px, py, r;
    scanf("%d %d %d", &px, &py, &r);
    r *= r;
    for(int i = aft[0]; i <= n; i = aft[i]) {
      if((px - x[i])*(px - x[i]) + (py - y[i])*(py - y[i]) <= r) {
        int now = bef[i];
        del(i);
      }
    }
  }
  int ans = 0;
  for(int i = aft[0]; i <= n; i = aft[i]) ans++;
  cout << ans << endl;
  return 0;
}
