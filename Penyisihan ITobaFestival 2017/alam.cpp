#include <bits/stdc++.h>

using namespace std;

const int N = 105;

long long a[N];
bool lembah[N], bukit[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  for (int i = 0; i < n; i++) lembah[i] = bukit[i] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i-1] < a[i]) {
      lembah[i] = 0;
    } else if (a[i-1] > a[i]) {
      bukit[i] = 0;
    } else {
      assert(0);
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i+1]) {
      bukit[i] = 0;
    } else if (a[i] > a[i+1]) {
      lembah[i] = 0;
    } else {
      assert(0);
    }
  }
  int buk = 0, lem = 0;
  for (int i = 0; i < n; i++) {
    buk += bukit[i];
    lem += lembah[i];
  }
  printf("%d %d\n", buk, lem);
  return 0;
}
