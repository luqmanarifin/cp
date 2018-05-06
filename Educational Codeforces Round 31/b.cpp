
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int sum = 0;
  for (int i = 0; i < n; i++) scanf("%d", a + i), sum += a[i];
  sum += n - 1;
  puts(x == sum? "YES" : "NO");

  return 0;
}
