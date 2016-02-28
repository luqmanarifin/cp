#include <bits/stdc++.h>

using namespace std;

int x[2], y[2];

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  for(int i = 0; i < 2; i++) {
    scanf("%d %d", x + i, y + i);
  }
  for(int mask = 0; mask < (1 << 2); mask++) {
    for(int i = 0; i < 2; i++) {
      if(mask & (1 << i)) {
        swap(x[i], y[i]);
      }
    }
    if(x[0] + x[1] <= a && max(y[0], y[1]) <= b) {
      puts("YES");
      return 0;
    }
    if(x[0] + x[1] <= b && max(y[0], y[1]) <= a) {
      puts("YES");
      return 0;
    }
    for(int i = 0; i < 2; i++) {
      if(mask & (1 << i)) {
        swap(x[i], y[i]);
      }
    }
  }
  puts("NO");
  return 0;
}
