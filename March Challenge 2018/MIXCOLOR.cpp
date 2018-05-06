
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s.count(a[i])) {
        ans++;
      } else {
        s.insert(a[i]);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
