#include <bits/stdc++.h>

using namespace std;

int a[1006];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  for(int i = 1; i < n; i++) if(a[i] % 2 == a[i - 1] % 2) return 0 * puts("0");
  puts("1");
  return 0;
}