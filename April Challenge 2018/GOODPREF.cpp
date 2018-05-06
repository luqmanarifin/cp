
#include <bits/stdc++.h>

using namespace std;

const int OFFSET = 1000;
const int N = 2005;

int pre[N];
char s[N];

int find(int l, int r) {
  return pre[r] - (l? pre[l - 1] : 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(pre, 0, sizeof(pre));

    int d;
    scanf("%s %d", s, &d);
    int n = strlen(s);
    int now = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        now++;
      } else {
        now--;
      }
      pre[now + OFFSET]++;
    }
    for (int i = 1; i < N; i++) pre[i] += pre[i - 1];

    if (now == 0) {
      printf("%lld\n", 1LL * find(1 + OFFSET, N - 1) * d);
      continue;
    }

    int l = 1 + OFFSET, r = N - 1;
    long long ans = 0;
    for (int i = 0; i < d; i++) {
      // printf("%d %d\n", l, r);
      ans += find(l, r);
      l -= now;
      l = max(l, 0);
      l = min(l, N);
      if (l == 0) {
        ans += 1LL * find(0, N - 1) * (d - i - 1);
        break;
      }
      if (l > r) {
        break;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
