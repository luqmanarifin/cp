#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i + 1 <= n; i += 2) {
      swap(a[i], a[i + 1]);
    }
    if (n % 2) swap(a[n - 1], a[n]);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
  }
  return 0;
}