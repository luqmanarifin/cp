#include <bits/stdc++.h>

using namespace std;

const int N = 105;

bool done[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(done, 0, sizeof(done));

    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (!done[v]) {
        ans++;
        done[v] = 1;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
