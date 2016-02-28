#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

long long bit[N][2];
int n;

void add(int at, int t, long long val) {
  for(; at <= n; at |= at + 1) {
    bit[at][t] += val;
    bit[at][t] %= mod;
  }
}

long long find(int at, int t) {
  long long ret = 0;
  for(; at >= 0; at = (at & (at + 1)) - 1) {
    ret += bit[at][t];
  }
  return ret % mod;
}

long long find(int l, int r, int t) {
  long long ret = find(r, t) - find(l - 1, t);
  ret = (ret + mod) % mod;
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int k;
    scanf("%d %d", &n, &k);
    if(n == 0) {
      puts("1");
      continue;
    }
    if(k == 0) {
      puts("0");
      continue;
    }
    add(0, 0, 1);
    add(0, 1, 1);
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < 2; j++) {
        long long ways = find(max(0, i - k), i - 1, j ^ 1);
        add(i, j, ways);
      }
    }
    long long ans = find(n, n, 0) + find(n, n, 1);
    printf("%d\n", (int) (ans % mod));
    
    for(int i = 0; i <= n; i++) {
      bit[i][0] = bit[i][1] = 0;
    }
  }
  
  return 0;
}
