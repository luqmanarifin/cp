#include <bits/stdc++.h>

using namespace std;

const string NAME = "adjustment";

set<int> dr, dc;

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

long long sum(int l, int r) {
  return sum(r) - sum(l - 1);
}

int main() {
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
  
  long long sumr = 0, cntr = 0, sumc = 0, cntc = 0;
  int n, q;
  scanf("%d %d", &n, &q);
  while (q--) {
    char c;
    int k;
    scanf(" %c %d", &c, &k);
    if (c == 'R') {
      if (dr.count(k)) {
        puts("0");
        continue;
      }
      dr.insert(k);
      long long tot = sum(k + 1, k + n);
      tot -= sumc + cntc * k;
      
      printf("%lld\n", tot);
      
      sumr += k;
      cntr++;
    } else {
      if (dc.count(k)) {
        puts("0");
        continue;
      }
      dc.insert(k);
      long long tot = sum(k + 1, k + n);
      tot -= sumr + cntr * k;
      
      printf("%lld\n", tot);
      
      sumc += k;
      cntc++;
    }
  }
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}
