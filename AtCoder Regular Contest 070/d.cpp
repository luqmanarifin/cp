#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

bool done[N];
int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int ans = 0;
  for (int skip = 0; skip < n; skip++) {
    memset(done, 0, sizeof(done));

    done[0] = 1;
    for (int i = 0; i < n; i++) if (i != skip) {
      for (int j = N - 1; j >= a[i]; j--) if (done[j - a[i]]) {
        done[j] = 1;
      }
    }
    bool ada = 0;
    for (int i = max(0, k - a[skip]); i < k; i++) {
      if (done[i]) ada = 1;
    }
    if (!ada) ans++;
  }
  cout << ans << endl;
  return 0;
}
