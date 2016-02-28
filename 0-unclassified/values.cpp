#include <bits/stdc++.h>

using namespace std;

const long long N = 1e7 + 5;

long long bit[N], a[N];
long long n;

void add(long long at, long long val) {
  for(; at < n; at |= at + 1) {
    bit[at] += val;
  }
}

long long get(long long at) {
  long long ret = 0;
  for(; at >= 0; at = (at & (at + 1)) - 1) {
    ret += bit[at];
  }
  return ret;
}

vector<long long> pos;
long long at[N], val[N], l[N], r[N];

long long id(long long v) {
  return lower_bound(pos.begin(), pos.end(), v) - pos.begin();
}

int main() {
  long long q;
  scanf("%I64d %I64d", &n, &q);
  
  for(long long i = 0; i < q; i++) {
    scanf("%I64d %I64d %I64d %I64d", &at[i], &val[i], &l[i], &r[i]);
    pos.push_back(at[i]);
    pos.push_back(l[i]);
    pos.push_back(r[i]);
  }
  sort(pos.begin(), pos.end());
  pos.resize(distance(pos.begin(), unique(pos.begin(), pos.end())));
  
  for(long long i = 0; i < q; i++) {
    long long t;
    t = id(at[i]);
    at[i] = t;
    
    t = id(l[i]);
    l[i] = t;
    
    t = id(r[i]);
    r[i] = t;
    
    add(at[i], -a[at[i]]);
    add(at[i], +val[i]);
    a[at[i]] = val[i];
    printf("%I64d\n", get(r[i]) - get(l[i] - 1));
  }
  return 0;
}
