#include <bits/stdc++.h>

using namespace std;

vector<long long> bit, a;
int n;

void add(int at, long long val) {
  for(; at < n; at |= at + 1) {
    //printf("iter %d\n", at);
    bit[at] += val;
  }
}

long long get(int at) {
  long long ret = 0;
  for(; at >= 0; at = (at & (at + 1)) - 1) {
    ret += bit[at];
  }
  return ret;
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  bit.resize(n + 1);
  a.resize(n + 1);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
  }
  while(q--) {
    int at, l, r;
    long long val;
    scanf("%d %d %I64d %d", &l, &r, &val, &at);
    add(l, val);
    add(r + 1, -val);
    
    printf("%I64d\n", get(at) + a[at]);
  }
  
  return 0;
}
