#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int ALL = 1e4 + 5;

int a[N][N];
int m[N];
int aft[ALL], done[ALL], cnt[ALL];

int main() {
  int n, tt = 0;
  while (scanf("%d", &n) == 1) {
    memset(aft, 0, sizeof(aft));
    memset(done, 0, sizeof(done));
    memset(cnt, 0, sizeof(cnt));
    
    vector<int> uniq;
    for (int i = 0; i < n; i++) {
      scanf("%d", m + i);
      for (int j = 0; j < m[i]; j++) {
        scanf("%d", &a[i][j]);
        uniq.push_back(a[i][j]);
        cnt[a[i][j]]++;
      }
    }
    sort(uniq.begin(), uniq.end());
    uniq.resize(distance(uniq.begin(), unique(uniq.begin(), uniq.end())));
    for (int i = 1; i < uniq.size(); i++) {
      aft[uniq[i-1]] = uniq[i];
    }
    int ans = 0, all_comp = 0;
    for (int i = 0; i < n; i++) {
      vector<pair<int, int>> p;
      int comp = 0;
      for (int j = 0; j < m[i]; j++) {
        int k = j;
        while (k + 1 < m[i] && a[i][k + 1] == a[i][k]) k++;
        p.emplace_back(a[i][j], k - j + 1);
        j = k;
      }
      for (int j = 0; j < p.size(); j++) {
        comp++;
        if (j + 1 < p.size() && aft[p[j].first] == p[j + 1].first && !done[p[j].first]) {
          done[p[j].first] = 1;
          
          int k = j + 1;
          while (k + 1 < p.size() && !done[p[k].first] && aft[p[k].first] == p[k + 1].first && p[k].second == cnt[p[k].first]) {
            done[p[k].first] = 1;
            k++;
          }
          j = k;
        }
      }
      ans += comp - 1;
      all_comp += comp;
    }
    ans += all_comp - 1;
    printf("Case %d: %d\n", ++tt, ans);
  } 
  
  return 0;
}
