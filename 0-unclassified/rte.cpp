#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    bool found = 0;
    for(int i = 0; i < n; i++) {
      int l = 0, r = n - 1;
      while(l < r) {
        int mid = (l + r) >> 1;
        if(1LL * a[i] * a[mid] >= k) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if(1LL * a[i] * a[l] == k && i != l) {
        found = 1;
        printf("%d %d\n", a[i], a[l]);
        break;
      }
    }
    if(!found) puts("-1");
  }
  
  return 0;
}
