#include <bits/stdc++.h>

using namespace std;

int a[5];
int step;

int solve(char x, char y, char z, int n) {
  if (n > 0) {
    if (solve(x, z, y, n - 1) == 0) return 0;
    //printf("disk %d from %c to %c\n", n, x, y);
    a[x - 'A']--;
    a[y - 'A']++;
    step++;
    if (a[0] == a[1] && a[1] == a[2]) {
      cout << step << endl;
      return 0;
    }
    if (solve(z, y, x, n - 1) == 0) return 0;
  }
  return 1;
}

#define LOCAL

int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  for (int n = 3; n <= 300; n += 3) {
    memset(a, 0, sizeof(a));
    a[0] = n;
    step = 0;
    solve('A', 'B', 'C', n);
    cerr << n << " done!" << endl; 
  }

  return 0;
}
