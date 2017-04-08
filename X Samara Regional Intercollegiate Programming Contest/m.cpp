#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    tot += a[i];
  }
  if (tot > n - 1) {
    puts("NO");
  } else {
    puts("YES");
    int killed = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < a[i]; j++) {
        printf("%d %d\n", i + 1, n - killed);
        killed++;
      }
    }
  }

  return 0;
}
