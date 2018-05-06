
#include <bits/stdc++.h>

using namespace std;

const long long PRIME = 89;
const long long MOD = (long long) 1e9 + 4207;
const int N = 5005;

long long power[N];
char s[N][N];
vector<long long> ada[N];
long long ori[N];

int main() {
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = power[i - 1] * PRIME % MOD;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    long long now = 0;
    for (int j = 0; j < m; j++) {
      now += (s[i][j] - 'a' + 1) * power[j]; 
      now %= MOD;
    }
    ori[i] = now;
    bool same = 0;
    for (int j = 0; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        if (s[i][j] == s[i][k]) {
          if (same) continue;
          same = 1;
        }
        long long cur = now;
        
        cur += (s[i][j] - 'a' + 1) * power[k] - (s[i][j] - 'a' + 1) * power[j];
        cur += (s[i][k] - 'a' + 1) * power[j] - (s[i][k] - 'a' + 1) * power[k];
        cur %= MOD;
        
        if (cur < 0) cur += MOD;
        ada[i].push_back(cur);
      }
    }
  }
  set<long long> v;
  for (auto it : ada[0]) v.insert(it);
  for (int i = 1; i < n; i++) {
    set<long long> nex;
    for (auto it : ada[i]) if (v.count(it)) {
      nex.insert(it);
    }
    v = nex;
    if (nex.empty()) {
      puts("-1");
      return 0;
    }
  }
  long long ans = *(v.begin());
  for (int j = 0; j < m; j++) {
    for (int k = j + 1; k < m; k++) {
      long long cur = ori[0];
      int i = 0;
      cur += (s[i][j] - 'a' + 1) * power[k] - (s[i][j] - 'a' + 1) * power[j];
      cur += (s[i][k] - 'a' + 1) * power[j] - (s[i][k] - 'a' + 1) * power[k];
      cur %= MOD;
      
      if (cur < 0) cur += MOD;
      
      if (cur == ans) {
        swap(s[0][j], s[0][k]);
        printf("%s\n", s[0]);
        return 0;
      }
    }
  }
  assert(0);
  return 0;
}
