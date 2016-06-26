#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  for(int k = 0; k < 2; k++) {
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        if(c + e <= a && f <= b && d <= b) {
          puts("YES");
          return 0;
        }
        swap(e, f);
      }
      swap(c, d);
    }
    swap(a, b);
  }
  puts("NO");
  return 0;
}
