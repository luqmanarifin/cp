#include <bits/stdc++.h>

using namespace std;

const string NAME = "gcd";

const int N = 1e4 + 4;
bitset<N> bs;

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  vector< int > prime;
  for (int i = 2; i <= n; ++i) {
    if (bs[i]) continue;
    prime.push_back(i);
    for (int j = i+i; j <= n; j += i)
      bs[j] = 1;
  }
  int ans = 0;
  for (int i = (int)prime.size()-1; i >= 0; --i) {
    if (bs[prime[i]]) continue;
    int now = prime[i];
    for (int j = i-1; j >= 0; --j) {
      if (bs[prime[j]]) continue;
      if (now * prime[j] <= n) {
        now *= prime[j];
        bs[prime[j]] = 1;
      }
    }
    ++ans;
  }
  printf("%d\n", ans);
  


#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}
