#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    int n,  k;
    scanf("%d%d", &n, &k);
    long long tot = 0;
    long long maks = 0;
    for(int i = 0; i < n; ++i){
      long long x;
      scanf("%lld", &x);
      maks = max(maks, x);
      tot += x;
    }
    maks = max(maks, (tot + k - 1) / k); 
    printf("%lld\n", maks);
  }

  return 0;
}