#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  } 
  for(int it = 0; it < n; it++) {
    for(int i = 0; i < n; i++) {
      a[i] = a[i] + (i % 2? -1 : 1);
      a[i] %= n;
      if(a[i] < 0) {
        a[i] += n;
      }
    }
    bool good = 1;
    for(int i = 0; i < n; i++) {
      if(a[i] != i) {
        good = 0;
        break;
      }
    }
    if(good) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
