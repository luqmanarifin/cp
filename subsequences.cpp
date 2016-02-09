#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

long long f[N];

void add(int i, long long val) {
  for(; i < N; i |= i + 1) {
    f[i] += val;
    if(f[i] >= mod) {
      f[i] -= mod;
    }
  }
}

long long get(int i) {
  long long ret = 0;
  for(; i >= 0; i = (i & (i + 1)) - 1) {
    ret += f[i];
  }
  return ret % mod;
}

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int a;
    scanf("%d", &a);
    long long sum = get(a);
    long long self = get(a) - get(a - 1);
    if(self < 0) self += mod;
    add(a, -self + mod);
    add(a, (sum * a + a) % mod);
  }
  cout << get(N - 1) << endl;
  return 0;
}
