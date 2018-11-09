#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    reverse(a, a + n);
    // for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
    while (k < n && a[k] == a[k - 1]) k++;
    printf("%d\n", k);
  } 
  
  return 0;
}
