#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int ca[N], cb[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(ca, 0, sizeof(ca));
    memset(cb, 0, sizeof(cb));
    for(int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      ca[a]++;
    }
    for(int i = 0; i < m; i++) {
      int a;
      scanf("%d", &a);
      cb[a]++;
    }
    int j = 1;
    bool good = 1;
    for(int i = 5; i <= 15; i++) {
      if(ca[i] == 0) continue;
      while(j <= 50 && cb[j] < ca[i]) j++;
      if(j <= 50 && cb[j] >= ca[i]) {
        j++;
      } else {
        good = 0;
        break;
      }
    }
    puts(good? "YES" : "NO");
  }
  return 0;
}
