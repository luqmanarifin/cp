#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int v[N];
int a[2];
int done[10];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", v + i);
    }
    a[0] = a[1] = 0;
    memset(done, 0, sizeof(done));
    
    int turn = 0;
    int red = 15;
    for (int i = 0; i < n; i++) {
      if (v[i] == 0) {
        turn ^= 1;
      } else {
        a[turn] += v[i];
        if (red == 0) done[v[i]] = 1;
        if (v[i] == 1) red--;
      }
      int all = 0;
      if (red) {
        all += red * 8 + 27;
      } else {
        for (int i = 2; i <= 7; i++) if (!done[i]) {
          all += i;
        }
      }
      //printf("%d %d %d\n", a[0], a[1], all);
      if (a[turn ^ 1] + all < a[turn]) {
        printf("%d\n", i + 1);
        break;
      }
    }
  }

  return 0;
}
