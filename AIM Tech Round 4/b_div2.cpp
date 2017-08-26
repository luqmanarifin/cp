#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &s[i][j]);
    }
  }
  long long ans = n * m;
  for (int i = 0; i < n; i++) {
    int zero = 0;
    int one = 0;
    for (int j = 0; j < m; j++) {
      if (s[i][j]) {
        one++;
      } else {
        zero++;
      }
    }
    ans += (1LL << zero) - 1 - zero;
    ans += (1LL << one) - 1 - one;
  }
  for (int j = 0; j < m; j++) {
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
      if (s[i][j]) {
        one++;
      } else {
        zero++;
      }
    }
    ans += (1LL << zero) - 1 - zero;
    ans += (1LL << one) - 1 - one;
  }
  cout << ans << endl;
  return 0;
}
