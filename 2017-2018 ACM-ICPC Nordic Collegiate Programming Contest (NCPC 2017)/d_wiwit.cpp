#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
char s[30];
 int n, k;
int calc(int b) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, k - __builtin_popcount(a[i] ^ b));
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int z = 0;
    scanf("%s", s);
    for (int j = 0; j < k; j++) {
      z <<= 1;
      z |= s[j] == '1';
    }
    a[i] = z;
  }
  int now = 0, val = calc(now);
  while (1) {
    bool fnd = 0;
    for (int j = 0; j < k; j++) {
      int nval = calc(now ^ (1 << j));
      if (nval < val) {
        val = nval;
        fnd = 1;
        now ^= (1 << j);
        break;
      }
    }
    if (!fnd) break;
  }
  for (int j = k-1; j >= 0; j--)
    printf("%c", (now & (1<<j)) ? '1' : '0');
  printf("\n");
  return 0;
}