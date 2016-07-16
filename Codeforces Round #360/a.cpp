#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  swap(n, m);
  for(int i = 0; i < n; i++) scanf("%s", s[i]);
  int ans = 0, cur = 0;
  for(int i = 0; i < n; i++) {
    bool all = 1;
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '0') {
        all = 0;
      }
    }
    if(all) {
      cur = 0;
    } else {
      cur++;
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;

  return 0;
}
