#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int n, a, b;
  scanf("%d %d %d %s", &n, &a, &b, s);
  int all = 0, luar = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      if (all + 1 <= a + b) {
        all++;
        puts("Yes");
      } else {
        puts("No");
      }
    } else if (s[i] == 'b') {
      if (all + 1 <= a + b && luar + 1 <= b) {
        all++;
        luar++;
        puts("Yes");
      } else {
        puts("No");
      }
    } else {
      puts("No");
    }
  }
  
  return 0;
}