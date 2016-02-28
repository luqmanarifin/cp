#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  int t;
  scanf("%d", &t);
  long long cuk = 0;
  for(int tt = 1; tt <= t; tt++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    cuk += 1LL * n * m;
    vector<int> h, f;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int side = 0;
        for(int d = 0; d < 4; d++) {
          int ti = i + dx[d];
          int tj = j + dy[d];
          if(0 <= ti && ti < n && 0 <= tj && tj < m) {
            side++;
          }
        }
        if((i + j) & 1) h.push_back(side);
        else f.push_back(side);
      }
    }
    sort(h.begin(), h.end());
    sort(f.begin(), f.end());
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < k - (int) f.size(); i++) {
      ans1 += h[i];
    }
    for(int i = 0; i < k - (int) h.size(); i++) {
      ans2 += f[i];
    }
    printf("Case #%d: %d\n", tt, min(ans1, ans2));
  }
  cerr << cuk << endl;
  return 0;
}
