#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

int w[3];

int main() {
  int n, a, b, c;
  scanf("%d", &n);
  for(int i = 0; i < 3; i++) scanf("%d", w + i);
  sort(w, w + 3);
  
  long long ans = inf;
  do {
    a = w[0];
    b = w[1];
    c = w[2];
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i * j > n) break;
        int k = n / (i * j);
        int rem = n % (i * j);
        long long base = 2LL*i*a*j*b + 2LL*i*a*k*c + 2LL*j*b*k*c;
        if(rem) {
          ans = min(ans, base + 2LL*i*a*c + 2LL*j*b*c);
        } else {
          ans = min(ans, base);
        }
      }
    }
  } while(next_permutation(w, w + 3));
  cout << ans << endl;
  return 0;
}