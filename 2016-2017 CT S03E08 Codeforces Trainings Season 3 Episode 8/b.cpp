#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector<int> a[N];
// ID, nomor
set<pair<int, int>> shelf[N];

int main() {
  int m, c, n;
  scanf("%d %d %d", &m, &c, &n);
  while (m || c || n) {
    for (int i = 0; i < N; i++) a[i].clear();
    for (int i = 0; i < N; i++) shelf[i].clear();
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      for (int j = 0; j < k; j++) {
        int v;
        scanf("%d", &v);
        a[i].push_back(v);
      }
      maxi = max(maxi, k);
    }
    for (int i = 0; i <= 100; i++) shelf[m + 1].insert({i, -1});
    
    int ans = 0;
    for (int j = 0; j < maxi; j++) {
      for (int i = 0; i < n; i++) {
        int id = j * n + i;
        if (j >= a[i].size()) continue;
        
        for (int it = 1; it <= m + 1; it++) {
          auto iter = shelf[it].lower_bound({a[i][j], -1});
          if (iter != shelf[it].end() && iter->first == a[i][j]) {
            ans += it;
            shelf[it].erase(iter);
            break;
          }
        }
        if (shelf[1].size() < c) {
          shelf[1].insert({a[i][j], id});
          ans += 1;
        } else {
          bool done = 0;
          int p = -1;
          for (int it = 1; it <= m; it++) {
            if (shelf[it].size() < c) {
              shelf[it].insert({a[i][j], id});
              ans += it;
              done = 1;
              p = it;
              break;
            }
          }
          if (!done) {
            shelf[m + 1].insert({a[i][j], id});
            ans += m + 1;
            p = m + 1;
          }
          
          // LRU, ID buku
          pair<int, int> mini = {1e9, 1e9};
          for (auto iter : shelf[1]) {
            mini = min(mini, make_pair(iter.second, iter.first));
          }
          shelf[1].erase({mini.second, mini.first});
          ans += 1;
          
          done = 0;
          for (int it = 2; it <= m; it++) {
            if (shelf[it].size() < c) {
              shelf[it].insert({mini.second, id});
              ans += it;
              done = 1;
              break;
            }
          }
          if (!done) {
            shelf[m + 1].insert({mini.second, id});
            ans += m + 1;
          }
          
          ans += p;
          shelf[p].erase({a[i][j], id});
          
          ans += 1;
          shelf[1].insert({a[i][j], id});
        }
        
      }
    }
    printf("%d\n", ans);
    
    scanf("%d %d %d", &m, &c, &n);
  }

  return 0;
}
