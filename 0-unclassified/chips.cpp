#include <bits/stdc++.h>

using namespace std;

bool row[1005], col[1005];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    row[a] = 1;
    col[b] = 1;
  }
  int ans = 0;
  for(int i = 2; i < n; i++) {
    if(row[i] == 0 && col[i] == 0) {
      if(n % 2 && i == n / 2 + 1) {
        ans++;
      } else {
        ans += 2;
      }
    } else if(row[i] == 0 || col[i] == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
