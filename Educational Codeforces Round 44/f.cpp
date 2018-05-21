#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long PRIME = 1e9 + 7;
const long long mod = 2e9 + 89;

long long h[N][26], power[N];
char s[N];
vector<int> pos[26];

long long find(int l, int r, int i) {
  long long tmp = h[r][i] - h[l-1][i] * power[r-l+1];
  tmp %= mod;
  if (tmp < 0) tmp += mod;
  return tmp;
}

int main() {
  power[0] = 1;
  for (int i = 1; i < N; i++) power[i] = power[i-1] * PRIME % mod;
  int n, q;
  scanf("%d %d %s", &n, &q, s + 1);
  for (int i = 1; i <= n; i++) {
    pos[s[i] - 'a'].push_back(i);
  }
  for (int j = 0; j < 26; j++) {
    for (int i = 1; i <= n; i++) {
      h[i][j] = h[i-1][j] * PRIME;
      if (j + 'a' == s[i]) {
        h[i][j]++;
      }
      h[i][j] %= mod;
    }
  }
  while (q--) {
    int l, r, len;
    scanf("%d %d %d", &l, &r, &len);
    map<int, int> mp;
    set<int> dif;
    for (int j = 0; j < 26; j++) {
      int p = lower_bound(pos[j].begin(), pos[j].end(), l) - pos[j].begin();
      if (p < pos[j].size() && pos[j][p] < l + len) {
        int k = s[r + pos[j][p] - l] - 'a';
        mp[j] = k;
        dif.insert(k);
      }
    }
    if (mp.size() != dif.size()) {
      puts("NO");
      continue;
    }
    bool done = 0;
    for (auto it : mp) {
      long long lef = find(l, l + len - 1, it.first);
      long long rig = find(r, r + len - 1, it.second);
      if (lef != rig) {
        puts("NO");
        done = 1;
        break;
      }
    }
    if (!done) puts("YES");
  }

  return 0;
}
