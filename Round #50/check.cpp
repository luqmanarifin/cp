#include <bits/stdc++.h>

using namespace std;

int x[5], y[5];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 4; i++) scanf("%d %d", x + i, y + i);
    vector<int> a;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        a.push_back(dx*dx + dy*dy);
      }
    }
    sort(a.begin(), a.end());
    printf("%d\n", (a[0] == a[3]) && (a[4] == a[5]) && (a[5] == a[0] * 2));
  }
  return 0;
}
