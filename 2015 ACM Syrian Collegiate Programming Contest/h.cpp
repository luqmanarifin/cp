#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    n = max(n, m);
    printf("%d\n", n * n);
  }
  
  return 0;
}
