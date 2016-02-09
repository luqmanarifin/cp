#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int l = i, r = n - 1;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(a[mid] < a[i] + 32) l = mid;
        else r = mid - 1;
      }
      ans += l - i;
    }
    cout << ans << endl;
  }
  
  return 0;
}
