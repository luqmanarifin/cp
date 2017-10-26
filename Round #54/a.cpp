#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int sum = 0;
  for (int i = 0; i < k; i++) sum += a[i];
  cout << (sum + 99) / 100 << endl;
  return 0;
}
