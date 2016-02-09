#include <bits/stdc++.h>

/**
2 3 1
148990 913922 18257
*/

using namespace std;

long long a, b, n, A;
long long l, t, m;

long long get(long long mid) {
  long long cnt = mid - l + 1;
  if(m == 1) {
    return cnt * (2 * A + b * (cnt - 1)) / 2;
  }
  long long need = 0;
  if(m < cnt) {
    long long N = cnt - m;
    long long move = N * (2 * A + b * (N - 1)) / 2 * (m - 1);
    long long low = a + (mid - m) * b;
    long long upp = a + (mid - 1) * b;
    long long lef = 0, rig = upp;
    while(lef < rig) {
      long long md = (lef + rig) >> 1;
      long long block = max(m - 1, (upp - md) / b);
      long long last = max(low, upp - b * block);
      long long del = block * (block + 1) / 2 * b;
      del += (block + 1) * (last - md);
      if(del > move) lef = md + 1;
      else rig = md;
    }
    need = N * (2 * A + b * (N - 1)) / 2 + lef;
  } else {
    need = a + (mid - 1) * b;
  }
  return need;
}

int main() {
  scanf("%I64d %I64d %I64d", &a, &b, &n);
  while(n--) {
    scanf("%I64d %I64d %I64d", &l, &t, &m);
    if(a + (l - 1) * b > t) {
      puts("-1");
      continue;
    }
    A = a + (l - 1) * b;
    
    long long lef = l, rig = l + 1000005LL; 
    while(lef < rig) {
      long long mid = (lef + rig + 1) >> 1;
      if(t < get(mid)) rig = mid - 1;
      else lef = mid;
    }
    
    printf("%I64d\n", lef);
  }
  
  return 0;
}
