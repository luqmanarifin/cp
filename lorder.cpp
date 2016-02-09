#include <bits/stdc++.h>

using namespace std;

int x[25], y[25];

int dist(int a, int b, int c, int d) {
  return (a - c)*(a - c) + (b - d)*(b - d);
}

int main() {
  int n, bx, by;
  scanf("%d %d %d", &bx, &by, &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  int ans = 1e9;
  for(int i = 0; i < n; i++) {
    
  }
  
  return 0;
}