
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int v[N];

int main() {
  int n;
  scanf("%d", &n);
  int maxi = -1e9, mini = 1e9;
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
    maxi = max(maxi, v[i]);
    mini = min(mini, v[i]);
  }
  if (maxi - mini <= 1) {
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    return 0;
  }
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == mini) {
      a++;
    } else if (v[i] == maxi) {
      c++;
    } else {
      b++;
    }
  }
  int ans = -1;
  if (min(a, c) * 2 > b / 2 * 2) {
    int p = min(a, c);
    ans = n - p * 2;
    b += 2 * p;
    a -= p;
    c -= p;
  } else {
    int p = b / 2;
    ans = n - p * 2;
    b -= 2 * p;
    a += p;
    c += p;
  }
  printf("%d\n", ans);
  while (a--) printf("%d ", mini);
  while (b--) printf("%d ", mini + 1);
  while (c--) printf("%d ", mini + 2);
  return 0;
}
