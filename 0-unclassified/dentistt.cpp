#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  int maks = 0;
  for(int i = 1; 2 * i - 1 <= n; i++) {
    cnt[i - 1]++;
    cnt[i]++;
    n -= 2 * i - 1;
    maks = i;
  }
  if(n > maks) {
    cnt[maks]++;
    cnt[n - maks]++;
  } else {
    cnt[n]++;
  }
  int ans = 0;
  for(int i = 1; i <= maks; i++) {
    ans += cnt[i];
  }
  printf("%d\n", ans);
  for(int i = 1; i <= maks; i++) {
    for(int j = 1; j < cnt[i]; j++) {
      printf("%d ", i);
    }
  }
  for(int i = maks; i >= 1; i--) {
    printf("%d ", i);
  }
  return 0;
}
