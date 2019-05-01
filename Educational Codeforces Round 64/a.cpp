#include <bits/stdc++.h>

using namespace std;

int a[5][5], s[105];

int main() {
  a[1][1] = -1;
  a[1][2] = 3;
  a[1][3] = 4;
  a[2][1] = 3;
  a[2][2] = -1;
  a[2][3] = -1;
  a[3][1] = 4;
  a[3][2] = -1;
  a[3][3] = -1;
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) scanf("%d", s + i);
  for (int i = 1; i < n; i++) {
    if (a[s[i-1]][s[i]] == -1) {
      puts("Infinite");
      return 0;
    }
    ans += a[s[i-1]][s[i]];
    if (i - 2 >= 0 && s[i-2] == 3 && s[i-1] == 1 && s[i] == 2) ans--;
  }
  puts("Finite");
  cout << ans << endl;
  return 0;
}
