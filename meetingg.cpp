#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

vector<pair<int, int>> p;
bool done[N];

main() {
  int xa, ya, xb, yb;
  scanf("%I64d %I64d %I64d %I64d", &xa, &ya, &xb, &yb);
  for(int i = min(xa, xb); i <= max(xa, xb); i++) {
    p.emplace_back(i, yb);
    p.emplace_back(i, ya);
  }
  for(int i = min(ya, yb); i <= max(ya, yb); i++) {
    p.emplace_back(xa, i);
    p.emplace_back(xb, i);
  }
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  
  int n;
  scanf("%I64d", &n);
  for(int it = 0; it < n; it++) {
    int a, b, r;
    scanf("%I64d %I64d %I64d", &a, &b, &r);
    for(int i = 0; i < p.size(); i++) {
      int dist = (a - p[i].first) * (a - p[i].first) + (b - p[i].second) * (b - p[i].second);
      if(dist <= r * r) {
        done[i] = 1;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < p.size(); i++) {
    if(!done[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
