#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

int a[N], n, m, lom, b[N];

bool can(int t) {
  int mini = 0, maxi = 0, d = 0;
  for(int i = 0; i < m; i++) {
    a[i] = b[i];
  }
  for(int i = 1; i < m; i++) {
    a[i] += d;
    int must = i * lom;
    if(must + t < a[i]) {
      int dif = a[i] - must - t;
      mini += dif;
      maxi += dif;
      d -= dif;
      mini = min(mini, -t);
    } else if(must - t > a[i]) {
      int dif = must - t - a[i];
      mini -= dif;
      maxi -= dif;
      d += dif;
      maxi = max(maxi, t);
    } else {
      mini = min(mini, must - a[i]);
      maxi = max(maxi, must - a[i]);
    }
    //printf("%d %d\n", mini, maxi);
    if(maxi > t) return 0;
    if(mini < -t) return 0;
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
      scanf("%d", b + i);
    }
    sort(b, b + m);
    for(int i = 1; i < m; i++) {
      b[i] -= b[0];
    }
    b[0] = 0;
    lom = n / m;
    int l = 0, r = n / 2;
    while(l < r) {
      int mid = (l + r) >> 1;
      if(can(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    
    printf("Case #%d: %d\n", tt, l);
  }
  
  return 0;
}
