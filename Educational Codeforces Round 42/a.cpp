
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int sum = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i), sum += a[i];
  int now = 0;
  for (int i = 0; i < n; i++) {
    now += a[i];
    if (now * 2 >= sum) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
