#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main() {
  int n = 3;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
  }
  bool a_same = 1;
  for(int i = 1; i < n; i++) {
    if(a[i] != a[0]) {
      a_same = 0;
    }
  }
  if(a_same) {
    puts("1");
    return 0;
  }
  bool b_same = 1;
  for(int i = 1; i < n; i++) {
    if(b[i] != b[0]) {
      b_same = 0;
    }
  }
  if(b_same) {
    puts("1");
    return 0;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      for(int k = 0; k < n; k++) {
        if(i == k || j == k) continue;
        if(a[i] == a[j]) {
          int l = min(b[i], b[j]);
          int r = max(b[i], b[j]);
          if(b[k] <= l || r <= b[k]) {
            puts("2");
            return 0;
          }
        }
        if(b[i] == b[j]) {
          int l = min(a[i], a[j]);
          int r = max(a[i], a[j]);
          if(a[k] <= l || r <= a[k]) {
            puts("2");
            return 0;
          }
        }
      }
    }
  }
  puts("3");
  return 0;
}
