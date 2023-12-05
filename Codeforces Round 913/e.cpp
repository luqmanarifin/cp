#include <bits/stdc++.h>

using namespace std;

int cnt[300];

int main() {
  cnt[0] = 1;
  cnt[1] = 3;
  cnt[2] = 6;
  cnt[3] = 10;
  cnt[4] = 15;
  cnt[5] = 21;
  cnt[6] = 28;
  cnt[7] = 36;
  cnt[8] = 45;
  cnt[9] = 55;

  int t;
  scanf("%d", &t);
  while (t--) {
    char s[20];
    scanf("%s", s);
    int n = strlen(s);
    long long ans = 1;
    for (int i = 0; i < n; i++) {
      ans *= cnt[s[i] - '0'];
    }
    printf("%lld\n", ans);
  }

  return 0;
}
