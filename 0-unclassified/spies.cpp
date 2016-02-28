#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<int, pair<int, int>> p;

int main() {
  int n, m, s, f;
  scanf("%d %d %d %d", &n, &m, &s, &f);
  for(int i = 0; i < m; i++) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    p[t] = {l, r};
  }
  int now = s;
  int d = (s < f? 1 : -1);
  for(int t = 1; now != f; t++) {
    int l = p[t].first, r = p[t].second;
    if((l <= now && now <= r) || (l <= now + d && now + d <= r)) {
      printf("X");
    } else {
      printf(d == 1? "R" : "L");
      now += d;
    }
  }
  return 0;
}
