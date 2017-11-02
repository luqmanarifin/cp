#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int p = -1;
    for (int i = 0; i < n; i++) if (a[i] != -1) p = i;
    for (int i = p + 1; i < n; i++) a[i] = (a[i - 1] + 1) % m;
    for (int i = p - 1; i >= 0; i--) a[i] = (a[i + 1] + m - 1) % m;
    for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
  }
  
  return 0;
}
