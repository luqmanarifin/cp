#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];
bool ok[N];
bool done[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i), ok[i] = 1;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (done[a[i]]) {
      ok[i] = 0;
    } else {
      ans++;
    }
    done[a[i]] = 1;
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) if (ok[i]) printf("%d ", a[i]);

  return 0;
}
