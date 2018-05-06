
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int BIG = 1e6 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) {
    if (a[i] % a[0]) {
      puts("-1");
      return 0;
    }
  }
  printf("%d\n", 2 * n);
  for (int i = 0; i < n; i++) printf("%d %d ", a[i], a[0]);
  return 0;
}
