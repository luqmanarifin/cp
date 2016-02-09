#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    long long s;
    scanf("%d %lld", &n, &s);
    assert(n <= s && s <= 1LL*n*(n + 1)/2);
    int ans = n - 1;
    s -= n;
    for(long long i = 1; i <= s; i++) {
      ans--;
      s -= i;
    }
    printf("%d\n" , ans);
  }
  
  return 0;
}