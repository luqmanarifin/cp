#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 5;
const int sq = 1e5 + 5;
const int mod = 1e9 + 9;

vector<int> p;
bool is[sq];
int l[sq], r[sq];

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

int main() {
  for(long long i = 2; i * i < N; i++) {
    if(!is[i]) {
      p.push_back(i);
      for(long long j = i * i; j * j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  //cout << p.size() << endl;
  long long k, d, m;
  scanf("%I64d %I64d %I64d", &k, &d, &m);
  for(int i = 0; i < p.size(); i++) {
    while(d % p[i] == 0) {
      l[i]++;
      d /= p[i];
    }
    while(m % p[i] == 0) {
      r[i]++;
      m /= p[i];
    }
  }
  if(m % d) {
    puts("0");
    return 0;
  }
  long long ans = 1;
  if(d != m) {
    int cnt = 2;
    long long add = power(cnt, k);
    add -= 2 * power(cnt - 1, k);
    add += power(cnt - 2, k);
    add %= mod;
    if(add < 0) add += mod;
    ans = ans * add % mod;
  }
  for(int i = 0; i < p.size(); i++) {
    if(r[i] < l[i]) {
      puts("0");
      return 0;
    }
    if(l[i] != r[i]) {
      int cnt = r[i] - l[i] + 1;
      long long add = power(cnt, k);
      add -= 2 * power(cnt - 1, k);
      add += power(cnt - 2, k);
      add %= mod;
      if(add < 0) add += mod;
      ans = ans * add % mod;
    }
  }
  cout << ans << endl;
  return 0;
}