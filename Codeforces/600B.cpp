#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d", b + i);
  
  // sort A
  sort(a, a + n);
  
  // cari jwaban
  for (int i = 0; i < m; i++) {
    // elemen terkecil yang > b[i]
    int l = 0;
    int r = n;
    while (l < r) {
      // tengah
      int mid = (l + r) / 2;
      if (a[mid] > b[i]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d ", l);
  }
  
  return 0;
}