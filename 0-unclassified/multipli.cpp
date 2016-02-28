// sad way to get AC because I only change int to long long. bad day :(
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if(b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

int cnt[N];
vector<long long> a, b, dep, bel;

long long sum(int num) {
  return 1LL * num * (num + 1) / 2;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    cnt[v]++;
    a.push_back(v);
  }
  sort(a.begin(), a.end());
  a.resize(distance(a.begin(), unique(a.begin(), a.end())));
  for(auto it : a) {
    b.push_back(cnt[it]);
  }
  int k = (int) a.size();
  dep.resize(k);
  bel.resize(k);
  for(int i = 0; i < k; i++) {
    dep[i] = b[i] + 1;
    if(i) dep[i] = dep[i] * dep[i - 1] % (mod - 1);
  }
  for(int i = k - 1; i >= 0; i--) {
    bel[i] = b[i] + 1;
    if(i < k - 1) bel[i] = bel[i] * bel[i + 1] % (mod - 1);
  }
  long long ans = 1;
  for(int i = 0; i < k; i++) {
    long long p = sum(b[i]) % (mod - 1);
    if(i) {
      p = p * dep[i - 1] % (mod - 1);
    }
    if(i + 1 < k) {
      p = p * bel[i + 1] % (mod - 1);
    }
    ans = ans * power(a[i], p) % mod;
  }
  cout << ans << endl;
  return 0;
}
