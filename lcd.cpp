#include <bits/stdc++.h>

using namespace std;

double dist(int dx, int dy) {
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    int x = n / 2;
    printf("Case #%d:\n", tt);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(dist(x - i, x - j) <= (n - 1) / 2) {
          printf("*");
        } else {
          printf(".");
        }
      }
      printf("\n");
    }
  }
  
  return 0;
}
