#include <bits/stdc++.h>

using namespace std;

int x[2005], y[2005];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        if((y[j] - y[i]) * (x[j] - x[k]) != (x[j] - x[i]) * (y[j] - y[k])) {
          ans++;
        }
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
