
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N][N];
int cnt[N][30], n, m;
bool coli;
int dif[N][N], len[N];
bool done[N][N];

void solve(int j1, int j2) {
  swap(s[0][j1], s[0][j2]);
  bool ok = 1;
  for (int i = 1; i < n; i++) {
    int beda = 0;
    for (int j = 0; j < len[i]; j++) {
      if (s[0][dif[i][j]] != s[i][dif[i][j]]) {
        beda++;
      }
    }
    if (!done[i][j1] && s[0][j1] != s[i][j1]) beda++;
    if (!done[i][j2] && s[0][j2] != s[i][j2]) beda++;
    if (beda == 2) continue;
    if (beda == 0 && coli) continue;
    ok = 0;
    break;
  }
  if (ok) {
    printf("%s\n", s[0]);
    exit(0);
  }
  swap(s[0][j1], s[0][j2]);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      cnt[i][s[i][j] - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
      if (cnt[i][j] != cnt[0][j]) {
        puts("-1");
        return 0;
      }
      if (cnt[i][j] > 1) {
        coli = 1;
      }
    }
    for (int j = 0; j < m; j++) {
      if (s[i][j] != s[0][j]) {
        done[i][j] = 1;
        dif[i][len[i]++] = j;
      }
    }
    if (len[i] > 4) {
      puts("-1");
      return 0;
    }
  }
  bool same = 0;
  for (int j = 0; j < m; j++) {
    for (int k = j + 1; k < m; k++) {
      if (s[0][j] == s[0][k]) {
        if (same) continue;
        same = 1;
      }
      solve(j, k);
    }
  }
  puts("-1");
  return 0;
}
