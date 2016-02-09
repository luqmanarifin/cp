#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int cnt[N], l[N], r[N];
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int maxi = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if(cnt[a[i]] == 0) {
      l[a[i]] = i;
    }
    r[a[i]] = i;
    cnt[a[i]]++;
    maxi = max(maxi, cnt[a[i]]);
  }
  int lef = 0, rig = n - 1;
  for(int i = 1; i < N; i++) {
    if(cnt[i] == maxi && r[i] - l[i] < rig - lef) {
      lef = l[i], rig = r[i];
    }
  }
  printf("%d %d\n", lef + 1, rig + 1);
  return 0;
}
