#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, s[N];

int solve_kiri() {
  for (int i = 1; i <= n; i++) s[i] = a[i];
  int mid = n / 2, ret = 0;
  for (int i = 2; i <= n; i++) {
    if (s[i] == mid) {
      swap(s[1], s[i]);
      ret++;
    }
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == mid + 1) {
      swap(s[i], s[n]);
      ret++;
    }
  }
  for (int i = 2; i < n; i += 2) {
    if (s[i] <= mid) {
      ret++;
    }
  }
  //printf("kiri %d\n", ret);
  return ret;
}

int solve_kanan() {
  for (int i = 1; i <= n; i++) s[i] = a[i];
  int mid = n / 2, ret = 0;
  for (int i = 2; i <= n; i++) {
    if (s[i] == mid + 1) {
      swap(s[1], s[i]);
      ret++;
    }
  }
  //for (int i = 1; i <= n; i++) printf("%d ", s[i]); printf("\n");
  for (int i = 1; i < n; i++) {
    if (s[i] == mid) {
      swap(s[i], s[n]);
      ret++;
    }
  }
  //for (int i = 1; i <= n; i++) printf("%d ", s[i]); printf("\n");
  for (int i = 2; i < n; i += 2) {
    if (s[i] > mid) {
      ret++;
    }
  }
  //printf("kanan %d\n", ret);
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    } 
    printf("%d\n", min(solve_kiri(), solve_kanan()));
  }

  return 0;
}