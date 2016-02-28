#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += s[i][i] - s[i][n - 1 - i];
  }
  cout << ans << endl;
  return 0;
}
