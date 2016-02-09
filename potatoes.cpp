#include <bits/stdc++.h>

using namespace std;

int main() {
  int y, k, n;
  scanf("%d %d %d", &y, &k, &n);
  int x = k - y % k;
  bool ada = 0;
  for(; x + y <= n; x += k) {
    ada = 1;
    printf("%d ", x);
  }
  if(!ada) {
    puts("-1");
  }
  return 0;
}
