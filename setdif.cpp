#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 1e5 + 5;

void norm(long long& cuk) {
  cuk %= mod;
  if(cuk < 0) cuk += mod;
}

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    long long now = 0, ans = 0, dua = 1;
    for(int i = 1; i < n; i++) {
      dua *= 2;
      norm(dua);
      if(i) {
        now = now * 2 + (a[i] - a[i - 1]) * (dua - 1);
        norm(now);
      }
      ans += now;
      //cout << "cuk " << now << endl;
    }
    norm(ans);
    printf("%lld\n", ans);
  }
  
  return 0;
}
