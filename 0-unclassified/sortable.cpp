#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m, p, k;
    scanf("%d %d %d %d %s", &n, &m, &p, &k, s);
    for(int i = 0; i < m; i++) {
      s[i] -= '0';
    }
    for(int i = 0; i < m; i++) {
      long long j = (i - 1LL * (n - 1) * p) % m;
      if(j < 0) j += m;
      printf("%d", (s[i] ^ s[j] ^ k));
    }
    printf("\n");
  }
  return 0;
}
