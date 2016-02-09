#include <bits/stdc++.h>

using namespace std;

int f[205];
bool done[205];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
  }
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    memset(done, 0, sizeof(done));
    int t = 0, now = i;
    while(!done[now] && now != f[now]) {
      done[now] = 1;
      t++;
      now = f[now];
    }
    ans = max(ans, t);
  }
  cout << ans << endl;
  return 0;
}
