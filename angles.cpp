#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int a[5], sum = 0;
    for(int i = 0; i < 3; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    sort(a, a + 3);
    puts(sum == 180 && a[0] != 0? "YES" : "NO");
  }
  
  return 0;
}
