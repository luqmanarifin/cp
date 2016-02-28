#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 5;
const long long mod = 1e9 + 7;

bool done[N], vis[N];
int siklik[N];

long long power(long long a, long long b, long long m) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2, m);
  temp = temp * temp % m;
  if(b & 1) {
    temp = temp * a % m;
  }
  return temp;
}

main() {
  long long p, k;
  scanf("%I64d %I64d", &p, &k);
  if(k == 0) {
    cout << power(p, p - 1, mod) << endl;
    return 0;
  }
  for(int i = 0; i < p; i++) {
    if(done[i]) continue;
    long long now = i;
    int cnt = 0;
    while(!done[now]) {
      done[now] = 1;
      cnt++;
      now = (now * k) % p;
    }
    assert(cnt > 0);
    siklik[cnt]++;
  }
  long long ans = 1;
  for(int i = 0; i < p; i++) {
    if(vis[i]) continue;
    int size = 0;
    long long now = i;
    while(!vis[now]) {
      vis[now] = 1;
      size++;
      now = (now * power(k, p - 2, p)) % p;
    }
    assert(size > 0);
    long long mul = 0;
    for(int i = 1; i * i <= size; i++) {
      if(size % i == 0) {
        mul += 1LL * siklik[i] * i;
        mul %= mod;
        if(i * i != size) {
          long long t = size / i;
          mul += 1LL * siklik[t] * t;
        }
        mul %= mod;
      } 
    }
    ans *= mul;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
