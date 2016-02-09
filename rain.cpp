#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 1005;

int a[N];
bool vis[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for(int it = 0; it <= 1000; it++) {
    memset(vis, 0, sizeof(vis));
    vis[1] = it <= a[1];
    for(int i = 1; i <= n; i++) {
      if(vis[i]) {
        for(int j = 1; j <= 2; j++) {
          if(i + j <= n && it <= a[i + j]) {
            vis[i + j] = 1;
          }
        }
      }
    }
    if(vis[n]) ans = it;
  }
  cout << ans << endl;
  return 0;
}
