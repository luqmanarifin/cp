
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int cnt[N][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v;
    char c;
    scanf("%d %c", &v, &c);
    cnt[v][c == 'L']++;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) ans += min(cnt[i][0], cnt[i][1]);
  cout << ans << endl;
  return 0;
}
