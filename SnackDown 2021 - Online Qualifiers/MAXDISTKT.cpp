#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int b[N], a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
      scanf("%d", b + i);
      p.emplace_back(b[i], i);
    }
    sort(p.begin(), p.end());
    int now = 0;
    for (int i = 0; i < n; i++) {
      if (now >= p[i].first) {
        a[p[i].second] = 0;
      } else {
        a[p[i].second] = now++;
      }
    }
    for (int i = 0; i < n; i++) printf("%d%c", a[i], (i == n - 1? '\n' : ' '));
  }

  return 0;
}
