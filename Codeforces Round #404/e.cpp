#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int MAGIC = 600;

int a[N], com[N], num[MAGIC];
int bit[MAGIC][N];

void update(int at, int i, int val) {
  for (; i < N; i |= i + 1) bit[at][i] += val;
}

int find(int at, int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[at][i];
  return ret;
}

int lower(int at, int i) {
  return find(at, i - 1);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) a[i] = i;
  for (int i = 0; i < n; i++) com[i] = i / MAGIC;
  for (int i = 0; i < n; i++) num[com[i]]++;
  for (int i = 0; i < n; i++) update(com[i], a[i], +1);
  
  long long ans = 0;
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    if (l == r) {
      printf("%I64d\n", ans);
      continue;
    }
    if (l > r) swap(l, r);
    for (int i = com[l] + 1; i < com[r]; i++) {
      int lower_l = lower(i, a[l]);
      int lower_r = lower(i, a[r]);
      ans += (num[i] - lower_l) - lower_l;
      ans += lower_r - (num[i] - lower_r);
    }
    if (com[l] == com[r]) {
      for (int i = l + 1; i < r; i++) {
        ans += (a[i] > a[l]) - (a[i] < a[l]);
        ans += (a[i] < a[r]) - (a[i] > a[r]);
      }
    } else {
      for (int i = l + 1; i < (com[l] + 1) * MAGIC; i++) {
        ans += (a[i] > a[l]) - (a[i] < a[l]);
        ans += (a[i] < a[r]) - (a[i] > a[r]);
      }
      for (int i = com[r] * MAGIC; i < r; i++) {
        ans += (a[i] > a[l]) - (a[i] < a[l]);
        ans += (a[i] < a[r]) - (a[i] > a[r]);
      }
    }
    if (a[l] < a[r]) {
      ans++;
    } else {
      ans--;
    }
    if (com[l] != com[r]) {
      update(com[l], a[l], -1);
      update(com[r], a[l], +1);
      update(com[r], a[r], -1);
      update(com[l], a[r], +1);
    }
    swap(a[l], a[r]);
    printf("%I64d\n", ans);
  }
  return 0;
}
