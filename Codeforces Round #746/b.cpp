#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], sorted[N]; 
bool can[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sorted[i] = a[i];
    }
    sort(sorted, sorted + n);
    for (int i = 0; i < n; i++) {
      if (i + x < n) {
        can[i] = can[i + x] = 1;
      }
    }
    bool solved = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] != sorted[i] && !can[i]) {
        solved = 0;
        break;
      }
    }
    puts(solved? "YES" : "NO");

    // clear
    for (int i = 0; i < n; i++) can[i] = 0;
  }

  return 0;
}
