#include <bits/stdc++.h>

using namespace std;

const int N = 105;

long long a[N];
bool lembah[N], bukit[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  assert(n > 1);
  int buk = 0, lem = 0;
  for (int i = 1; i < n; i++) assert(a[i] != a[i-1]);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (a[i] > a[i+1]) buk++;
      else if (a[i] < a[i+1]) lem++;
    } else if (i == n - 1) {
      if (a[i] > a[i-1]) buk++;
      else lem++;
    } else {
      if (a[i-1] < a[i] && a[i] > a[i+1]) buk++;
      if (a[i-1] > a[i] && a[i] < a[i+1]) lem++;
    }
  }
  printf("%d %d\n", buk, lem);
  return 0;
}
