#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    int p = 100 - a[n - 1];
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] + p >= 50) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
