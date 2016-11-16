#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("popcorn.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans = 1;
    for (int i = 0; i < m; i++) {
      ans = ans * (n - i) / (i + 1); 
    }
    cout << ans << endl;
  }  

  return 0;
}
