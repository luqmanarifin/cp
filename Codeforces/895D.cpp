#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long mod = 1e9 + 7;

long long fact[N], ifact[N];

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

string a, b;
int n, cnt[26], ans;

long long compute_bebas() {
  int tot = 0;
  for (int i = 0; i < 26; i++) tot += cnt[i];
  long long ret = fact[tot];
  for (int i = 0; i < 26; i++) if (cnt[i]) ret = ret * ifact[cnt[i]] % mod;
  return ret;
}

void solve_2(int x) {
  if (x >= n) return;
  long long now = fact[n - x - 1];
  for (int i = 0; i < 26; i++) now = (now * ifact[cnt[i]]) % mod;
  for (int i = a[x] + 1; i <= 'z'; i++) {
    int c = i - 'a';
    if (cnt[c]) {
      now = now * fact[cnt[c]] % mod * ifact[cnt[c]-1] % mod;
      add(ans, now);
      now = now * ifact[cnt[c]] % mod * fact[cnt[c]-1] % mod;
    }
  }
  if (cnt[a[x] - 'a']) {
    cnt[a[x] - 'a']--;
    solve_2(x + 1);
    cnt[a[x] - 'a']++;
  }
}

void solve_3(int x) {
  if (x >= n) return;
  long long now = fact[n - x - 1];
  for (int i = 0; i < 26; i++) now = (now * ifact[cnt[i]]) % mod;
  for (int i = 'a'; i < b[x]; i++) {
    int c = i - 'a';
    if (cnt[c]) {
      now = now * fact[cnt[c]] % mod * ifact[cnt[c]-1] % mod;
      add(ans, now);
      now = now * ifact[cnt[c]] % mod * fact[cnt[c]-1] % mod;
    }
  }
  if (cnt[b[x] - 'a']) {
    cnt[b[x] - 'a']--;
    solve_3(x + 1);
    cnt[b[x] - 'a']++;
  }
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i-1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  cin >> a >> b;
  n = a.size();
  for (int i = 0; i < n; i++) cnt[a[i] - 'a']++;
  if (a >= b) return 0;
  int x = 0;
  while (a[x] == b[x]) {
    cnt[a[x] - 'a']--;
    x++;
  }
  
  // kasus 1
  for (int i = a[x] + 1; i < b[x]; i++) {
    int c = i - 'a';
    if (cnt[c]) {
      cnt[c]--;
      add(ans, compute_bebas());
      cnt[c]++;
    }
  }
  
  // kasus 2
  if (cnt[a[x] - 'a']) {
    cnt[a[x] - 'a']--;
    solve_2(x + 1);
    cnt[a[x] - 'a']++;
  }
  
  // kasus 3
  if (cnt[b[x] - 'a']) {
    cnt[b[x] - 'a']--;
    solve_3(x + 1);
    cnt[b[x] - 'a']--;
  }
  
  cout << ans << endl;
  return 0;
}
