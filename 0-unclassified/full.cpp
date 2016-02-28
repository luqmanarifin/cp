#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int k, m, n;
    scanf("%d %d %d", &k, &m, &n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    int free = k - sum;
    int ans = 0;
    for(int i = 0; i < n && free < m; i++) {
      free += a[i];
      ans++;
    }
    cout << ans << endl;
  }
  
  return 0;
}
