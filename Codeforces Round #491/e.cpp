#include <bits/stdc++.h>

using namespace std;

const int N = 25;

long long fact[N];
int cnt[N];

int st[N], tot;
long long ans;

void dfs(int i) {
  if (i == 10) {
    // printf("tot %d\n", tot);
    // for (int p = 0; p <= 9; p++) printf("%d ", st[p]); printf("\n");
    for (int start = 1; start <= 9; start++) {
      if (st[start] == 0) continue;
      long long cur = fact[tot - 1];
      for (int p = 0; p <= 9; p++) {
        cur /= fact[st[p] - (p == start)];
      }
      ans += cur;
    }
    return;
  }
  for (int p = 1; p <= cnt[i]; p++) {
    st[i] = p;
    tot += p;
    dfs(i + 1);
    tot -= p;
  }
  if (cnt[i] == 0) dfs(i + 1);
}

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;
  string s;
  cin >> s;
  int len = s.length();
  for (int i = 0; i < len; i++) {
    cnt[s[i] - '0']++;
  }
  dfs(0);
  cout << ans << endl;
  return 0;
}
