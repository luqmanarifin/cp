#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

long long fact[N], ifact[N];

char s[N];
int cnt[N][26];
vector<int> pos[26];
bool DEBUG;

int count(int p, int l, int r) {
  return cnt[r][p] - cnt[l - 1][p];
}

long long c(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

long long power(long long p, long long q) {
  if (q == 0) return 1;
  long long temp = power(p, q / 2);
  temp = temp * temp % mod;
  if (q & 1) {
    temp = temp * p % mod;
  }
  return temp;
}

long long inv(long long v) {
  return power(v, mod - 2);
}

long long solve(vector<int>& a) {  
  vector<long long> s, sb, ss;
  s.resize(a.size());
  sb.resize(a.size());
  ss.resize(a.size());
  s[0] = a[0];
  for (int i = 1; i < a.size(); i++) {
    s[i] = s[i - 1] + a[i];
  }
  sb.back() = a.back();
  ss.back() = sb.back();
  for (int i = (int) a.size() - 2; i >= 0; i--) {
    sb[i] = sb[i + 1] + a[i];
    ss[i] = ss[i + 1] + sb[i];
  }
  /*
  if (DEBUG) {
    for (int i = 0; i < a.size(); i++) printf("%d ", a[i]); printf("\n");
    for (int i = 0; i < s.size(); i++) printf("%I64d ", s[i]); printf("\n");
    for (int i = 0; i < ss.size(); i++) printf("%I64d ", ss[i]); printf("\n");
    printf("\n");
  }
  */
  long long ret = 0;
  for (int i = 0; i + 2 < a.size(); i++) {
    ret += s[i] * ss[i + 2] % mod;
  }
  return ret % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    cnt[i][s[i] - 'a']++;
    pos[s[i] - 'a'].push_back(i);
    for (int j = 0; j < 26; j++) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }
  long long ans = 0;
  for (int p = 0; p < 26; p++) {
    ans += c(count(p, 1, n), 4);
    ans %= mod;
  }
  for (int p = 0; p < 26; p++) {
    for (int q = 0; q < 26; q++) {
      if (p == q) continue;
      vector<int> a;
      int now = 1;
      for (auto it : pos[p]) {
        a.push_back(count(q, now, it));
        now = it;
      }
      a.push_back(count(q, now, n));
      DEBUG = ((p == 6 && q == 7) || (p == 7 && q == 6));
      ans += solve(a);
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
