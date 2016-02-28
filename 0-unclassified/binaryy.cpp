#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int a;
    scanf("%d", &a);
    int ans = 0;
    for(int i = 0; i < 31; i++) {
      if(a & (1 << i)) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
