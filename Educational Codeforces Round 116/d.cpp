#include <bits/stdc++.h>

using namespace std;

const int inf = 1e7;

string build_string(int n, char c) {
  string ret = "";
  for (int i = 0; i < n; i++) ret.push_back(c);
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> max_lef(n, vector<int>(m));
    vector<vector<int>> min_lef(n, vector<int>(m));
    vector<vector<int>> min_rig(n, vector<int>(m));
    vector<vector<int>> max_rig(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        max_lef[i][j] = min_lef[i][j] = max_rig[i][j] = min_rig[i][j] = a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
        max_lef[i][j] = max(max_lef[i][j], max_lef[i][j - 1]);
        min_lef[i][j] = min(min_lef[i][j], min_lef[i][j - 1]);
      }
      for (int j = m - 2; j >= 0; j--) {
        max_rig[i][j] = max(max_rig[i][j], max_rig[i][j + 1]);
        min_rig[i][j] = min(min_rig[i][j], min_rig[i][j + 1]);
      }
    }
    bool found = 0;
    for (int j = 1; j < m; j++) {
      vector<tuple<int, int, int, int, int>> p; // max_rig, min_rig, max_lef, min_lef, id
      for (int i = 0; i < n; i++) {
        p.emplace_back(max_rig[i][j], min_rig[i][j], max_lef[i][j-1], min_lef[i][j-1], i);
      }
      sort(p.begin(), p.end());
      vector<int> min_rig_do(n);
      vector<int> max_lef_do(n);
      vector<int> min_lef_up(n);
      vector<int> max_rig_up(n);
      for (int i = 0; i < n; i++) {
        auto it = p[i];
        int b, c, d, e, id;
        tie(b, c, d, e, id) = it;
        max_rig_up[i] = b;
        min_rig_do[i] = c;
        max_lef_do[i] = d;
        min_lef_up[i] = e;
      }
      for (int i = 1; i < n; i++) {
        max_rig_up[i] = max(max_rig_up[i], max_rig_up[i-1]);
        min_lef_up[i] = min(min_lef_up[i], min_lef_up[i-1]); 
      }
      for (int i = n - 2; i >= 0; i--) {
        min_rig_do[i] = min(min_rig_do[i], min_rig_do[i+1]);
        max_lef_do[i] = max(max_lef_do[i], max_lef_do[i+1]);
      }
      for (int i = 0; i < n; i++) {
        int from = i;
        while (i + 1 < n && get<0>(p[i]) == get<0>(p[i+1])) i++;
        if (i + 1 == n) break;
        if (max_rig_up[i] < min_rig_do[i+1] && min_lef_up[i] > max_lef_do[i+1]) {
          found = 1;
          string ans = build_string(n, 'B');
          for (int k = 0; k <= i; k++) {
            int id;
            tie(ignore, ignore, ignore, ignore, id) = p[k];
            ans[id] = 'R';
          }
          printf("YES\n%s %d\n", ans.c_str(), j);
          goto HERE;
        }
      }
    }
    HERE:;
    if (!found) {
      printf("NO\n");
    }
  }

  return 0;
}
