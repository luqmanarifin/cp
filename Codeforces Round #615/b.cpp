#include <bits/stdc++.h>

using namespace std;

void move(pair<int, int> from, pair<int, int> to) {
  for (int i = 0; i < to.first - from.first; i++) printf("R");
  for (int i = 0; i < to.second - from.second; i++) printf("U");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      p.emplace_back(x, y);
    }
    sort(p.begin(), p.end());
    bool ok = 1;
    for (int i = 1; i < n; i++) {
      if (p[i-1].second > p[i].second) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      puts("YES");
      move(make_pair(0, 0), p[0]);
      for (int i = 1; i < n; i++) move(p[i-1], p[i]);
      printf("\n");
    } else {
      puts("NO");
    }
  }

  return 0;
}
