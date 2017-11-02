#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) tmp = tmp * a % mod;
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2); 
}

int a[N][10];

void dfs(int p, int to, long long now, map<long long, int>& cnt) {
  //printf("%d %d %lld\n", p, to, now);
  if (p == to) {
    cnt[now]++;
    return;
  }
  for (int i = 0; i < 6; i++) {
    dfs(p + 1, to, now * a[p][i] % mod, cnt);
  }
}

map<long long, int> first;
map<long long, int> second;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    first.clear();
    second.clear();
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < 6; j++) scanf("%d", &a[i][j]);
    long long ans = 0;
    if (n > 1) {
      dfs(0, n / 2, 1, first);
      dfs(n / 2, n, 1, second);
      //for (auto it : second) cout << "s " << it.first << " " << it.second << endl;
      for (auto it : first) {
        //cout << "f " << it.first << " " << it.second << endl;
        long long at = 1LL * m * inv(it.first) % mod;
        ans += 1LL * it.second * second[at];
      }
      //puts("ngentod");
    } else {
      dfs(0, n, 1, first);
      ans += first[m];
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}
