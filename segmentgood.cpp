#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], cnt[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int i = 0, j = 0, now = 1, best = -N, l, r;
  cnt[a[0]]++;
  for(int i = 0; i < n; i++) {
    if(j < i) {
      assert(j + 1 == i);
      j = i;
      now = 1;
      cnt[a[i]]++;
    }
    while(j + 1 < n && now + (cnt[a[j + 1]]? 0 : 1) <= k) {
      if(cnt[a[j + 1]] == 0) {
        now++;
      }
      cnt[a[j + 1]]++;
      j++;
    }
    if(j - i + 1 > best) {
      best = j - i + 1;
      l = i;
      r = j;
    }
    //printf("%d %d %d\n", i + 1, j + 1, now);
    cnt[a[i]]--;
    if(cnt[a[i]] == 0) {
      now--;
    }
  }
  printf("%d %d\n", l + 1, r + 1);
  return 0;
}
