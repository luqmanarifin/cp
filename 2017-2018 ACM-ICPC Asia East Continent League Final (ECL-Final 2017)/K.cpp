#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e5 + 5;
LL pref[N + 5];
int ar[N + 5];
int n, a, b;
int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; ++tc){
    scanf("%d%d%d", &a, &b, &n);
    for(int i = 1;i <= a; ++i) {
      scanf("%d", &ar[i]);
      if(i == 1) pref[i] = 1;
      else pref[i] = pref[i - 1] + ar[i - 1];
    }
    LL nowa = a;
    LL nowb = b;
    for(int i = 1;i <= n; ++i){
     // fprintf(stderr, "NOW %d: %d %d\n", i, nowa, nowb);
      int tmp = upper_bound(pref + 1, pref + a + 1, nowa) - pref - 1;
      LL nexta = (int)tmp;
      LL nextb = nowa - pref[tmp] + 1;
      if(nowa == nexta && nowb == nextb) break;
      nowa = nexta;
      nowb = nextb;
    }
    printf("Case #%d: %lld-%lld\n", tc, nowa, nowb);
  }

  return 0;
}

