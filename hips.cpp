#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int tot = n + m;
  printf("%d %d\n", min(n, m), (tot - 2*min(n, m)) / 2);
  
  return 0;
}
