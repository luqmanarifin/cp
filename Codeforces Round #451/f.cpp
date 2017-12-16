/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const int HASH = 4;
const int N = 1e6 + 5;
const long long mod[HASH] = {
  (long long) 1e9 + 9,
  (long long) 2e9 + 1851,
  (long long) 2e9 + 89,
  (long long) 1e9 + 4207
};

long long power[N][HASH], h[N][HASH];
int n;
char s[N];

long long find(int i, int l, int r) {
  long long val = h[r][i] - h[l - 1][i] * power[r-l+1][i];
  val %= mod[i];
  if (val < 0) val += mod[i];
  return val;
}

void print(int u, int v) {
  for (int i = 1; i <= u; i++) printf("%c", s[i]); printf("+");
  for (int i = u + 1; i <= v; i++) printf("%c", s[i]); printf("=");
  for (int i = v + 1; i <= n; i++) printf("%c", s[i]); printf("\n");
}

int main() {
  for (int j = 0; j < HASH; j++) power[0][j] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < HASH; j++) {
      power[i][j] = power[i-1][j] * 10 % mod[j];
    }
  }
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int j = 0; j < HASH; j++) {
    for (int i = 1; i <= n; i++) {
      h[i][j] = (h[i-1][j] * 10 + s[i] - '0') % mod[j];
    }
  }
  //puts("hash done");
  
  for (int i = 1; i + 2 <= n; i++) {
    //printf("iter %d\n", i);
    int l = i + 1, r = n - 1;
    while (r - l > 5) {
      int mid = (l + r) >> 1;
      int a = i, b = mid - i, c = n - mid;
      if (max(a, b) + 1 < c) {
        l = mid;
      } else {
        r = mid;
      }
    }
    //printf("til %d: %d %d\n", i, l, r);
    for (int k = max(l - 2, i + 1); k <= min(n - 1, r + 2); k++) {
      if (s[i + 1] == '0' && k - i > 1) continue;
      if (s[k + 1] == '0' && n - k > 1) continue;
      bool ok = 1;
      for (int j = 0; j < HASH; j++) {
        long long a = find(j, 1, i);
        long long b = find(j, i + 1, k);
        long long c = find(j, k + 1, n);
        //printf("%lld %lld %lld\n", a, b, c);
        if ((a + b) % mod[j] != c) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        print(i, k);
        return 0;
      }
    }
  }
  puts("fuck");
  return 0;
}
