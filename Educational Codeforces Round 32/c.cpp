
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int cnt[N][26], n;

int get(int l, int r, int c) {
  return cnt[r][c] - cnt[l - 1][c];
}

bool can(int len) {
  vector<bool> ada(26, 1);
  for (int i = 1; i + len - 1 <= n; i++) {
    for (int j = 0; j < 26; j++) {
      if (get(i, i + len - 1, j) == 0) {
        ada[j] = 0;
      }
    }
  }
  for (int i = 0; i < 26; i++) if (ada[i]) return 1;
  return 0;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) cnt[i][s[i] - 'a']++;
  for (int j = 0; j < 26; j++) {
    for (int i = 1; i <= n; i++) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }
  
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
