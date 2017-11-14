#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int M = 205;

string s[N];
int n, m;

int len[N];
int ans[N][M], ori[N];

// rule 1 ada batesan, 0 bebas
bool dfs(int p, int q, int st, int rule) {
  if (q == m) return 1;
  int til = len[p]-m+q;
  if (rule) {
    for (int i = st; i <= til; i++) {
      if (s[p][i] == ans[p][q]) {
        if (dfs(p, q + 1, i + 1, 1)) return 1;
        break;
      }
    }
    int best = 1e9, at = -1;
    for (int i = st; i <= til; i++) {
      if (s[p][i] > ans[p][q]) {
        if (s[p][i] < best) {
          best = s[p][i];
          at = i;
        }
      }
    }
    if (at == -1) return 0;
    ans[p][q] = s[p][at];
    assert(dfs(p, q + 1, at + 1, 0));
    return 1;
    
  } else {
    
    int best = 1e9, at = -1;
    for (int i = st; i <= til; i++) {
      if (s[p][i] < best) {
        best = s[p][i];
        at = i;
      }
    }
    ans[p][q] = s[p][at];
    assert(dfs(p, q + 1, at + 1, 0));
    return 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  vector<pair<string, int>> ss;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    ss.emplace_back(s[i], i);
  }
  sort(ss.begin(), ss.end());
  for (int i = 0; i < n; i++) {
    int at = ss[i].second;
    ori[at] = i;
    s[i] = ss[i].first;
  }
  for (int i = 0; i < n; i++) {
    len[i] = s[i].size(); 
    if (len[i] < m) {
      puts("NO");
      return 0;
    }
    for (int j = 0; j < len[i]; j++) {
      s[i][j] -= 'A';
    }
    ans[i][0] = s[i][0];
  }
  for (int i = 0; i < n; i++) {
    if (i && ans[i-1][0] == ans[i][0]) {
      for (int j = 0; j < m; j++) ans[i][j] = ans[i-1][j];
      bool ada = 0;
      for (int j = m - 1; j > 0; j--) {
        if (ans[i][j] < 25) {
          ada = 1;
          ans[i][j]++;
          break;
        } else {
          ans[i][j] = 0;
        }
      }
      if (!ada) {
        puts("NO");
        return 0;
      }
    }
    if (dfs(i, 1, 1, 1) == 0) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", ans[ori[i]][j] + 'A');
    }
    printf("\n");
  }

  return 0;
}
