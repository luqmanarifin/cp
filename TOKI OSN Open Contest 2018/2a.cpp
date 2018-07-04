#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

char s[N], junk[20];
long long n, tallest_at;
int k, len, a, b;
int lookup[N];

long long find(long long p) {
  if (p <= tallest_at) {
    int l = 0, r = k - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      long long now = 1 + 1LL * mid * a;
      if (p < now) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    long long base = 1 + 1LL * l * len;
    long long now = 1 + 1LL * l * a;
    return base + lookup[p - now];
  } else {
    int l = 0, r = k - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      long long now = n - 1LL * mid * b;
      if (now < p) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    long long base = 1 + 1LL * l * len;
    long long now = n - 1LL * l * b;
    return base + lookup[len-(now-p)];
  }
}

main() {
  int q;
  scanf("%s %s %lld %lld", junk, s, &k, &q);
  // if (junk[1] == '1') {
  //   puts("13");
  //   puts("12");
  //   puts("5");
  //   puts("7");
  //   puts("13");
  //   puts("5");
  //   return 0;
  // }
  len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] == 'B') {
      a++;
    } else {
      b++;
    }
  }
  int l = 0, r = len;
  for (int i = 0; i < len; i++) {
    if (s[i] == 'A') {
      r--;
    } else {
      l++;
    }
    lookup[l] = max(lookup[l], i + 1);
    lookup[r] = max(lookup[r], i + 1);
  }
  // printf("lookup "); for (int i = 0; i <= len; i++) printf("%lld ", lookup[i]); printf("\n");
  tallest_at = 1LL * a * k + 1;
  n = 1LL * len * k + 1;
  // printf("tallest at %lld\n", tallest_at);
  // printf("find "); for (int i = 1; i <= n; i++) printf("%lld ", find(i)); printf("\n");

  int len = strlen(s);
  while (q--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    if (l <= tallest_at && tallest_at <= r) {
      printf("%lld\n", n);
      continue;
    }
    printf("%lld\n", max(find(l), find(r)));
  }
  return 0;
}
