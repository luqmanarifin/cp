#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int cnt, k;

void merge(int l, int r) {
  if (l + 1 == r) return;
  if (cnt < k) {
    cnt += 2;
    int mid = (l + r) / 2;
    swap(a[mid-1], a[mid]);
    merge(l, mid);
    merge(mid, r);
  }
}

int main() {
  int n;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) a[i] = i;
  cnt = 1;
  merge(0, n);
  if (cnt == k) {
    for (int i = 0; i < n; i++) printf("%d ", a[i] + 1);
  } else {
    puts("-1");
  }
  return 0;
}
