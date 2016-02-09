#include <bits/stdc++.h>

using namespace std;

int main() {
  for(int n = 1; n <= 1000; n++) {
    int ans = 0;
    for(int i = 1; i < n; i++) {
      for(int j = 1; j < n; j++) {
        int k = n - i - j;
        if(k <= 0) continue;
        int a[] = {i, j, k};
        sort(a, a + 3);
        if(a[0] + a[1] > a[2]) {
          ans++;
          //printf("%d %d %d\n", i, j, k);
        }
      }
    }
    printf("%d, ", ans);
  }
  return 0;
}
