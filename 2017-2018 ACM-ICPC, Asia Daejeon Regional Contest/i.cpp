#include <bits/stdc++.h>

using namespace std;

const long long mod = 2e9 + 2153;
const long long prime = 1e9 + 9;
const int inf = 1e9;

const int N = 1e6 + 5;

int a[N];
long long h[N], pw[N];

long long get(int l, int r) {
  long long tmp = h[r] - h[l - 1] * pw[r - l + 1];
  tmp %= mod;
  if (tmp < 0) tmp += mod;
  return tmp;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = pw[i-1] * prime % mod;
  for (int i = 1; i <= n; i++) {
    h[i] = (h[i-1] * prime + a[i]) % mod;
  }
  long long asli = (423LL * prime + 3157) % mod;
  
  int k = inf, p = inf;
  for (int len = 1; len < n; len++) {
    long long root = get(n - len + 1, n);
    int same = len;
    for (int i = n - len; i >= 1; i -= len) {
      if (i - len + 1 >= 1 && get(i - len + 1, i) == root) {
        same += len;
      } else {
        int l = 0, r = len - 1;
        while (l < r) {
          int mid = (l + r + 1) >> 1;
          if (get(i - mid + 1, i) == get(n - mid + 1, n)) {
            l = mid;
          } else {
            r = mid - 1;
          }
        }
        same += l;
        break;
      }
    }
    //printf("period %d sampe %d\n", len, same);
    int curk = n - same;
    int curp = len;
    if (curk + curp < k + p) {
      k = curk;
      p = curp;
    } else if (curk + curp == k + p && curp < p) {
      k = curk;
      p = curp;
    }    
  }
  printf("%d %d\n", k, p);
  return 0;
}
