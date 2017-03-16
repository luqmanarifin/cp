#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;

int main() {
  int n;
  scanf("%d", &n);
  int beg = -inf, end = inf;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    beg = max(beg, a);
    end = min(end, b);
  }
  
  int m;
  scanf("%d", &m);
  int begi = -inf, endi = inf;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    begi = max(begi, a);
    endi = min(endi, b);
  }
  int ans = 0;
  ans = max(ans, beg - endi);
  ans = max(ans, begi - end);
  cout << ans << endl;
  return 0;
}
