#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int p = 0;
  int pol = -1;
  for(int i = (n % 2? 2 : 1); i < n; i += 2, p++) {
    a[p] = a[p + n - i] = i;
    pol = max(pol, p + n - i);
    //for(int i = 0; i < 2 * n; i++) printf("%d ", a[i]); printf("\n");
  }
  p = pol + 1;
  for(int i = (n % 2? 1 : 2); i < n; i += 2, p++) {
    a[p] = a[p + n - i] = i;
    pol = max(pol, p + n - i);
    //for(int i = 0; i < 2 * n; i++) printf("%d ", a[i]); printf("\n");
  }
  pol = max(pol, p);
  a[p] = a[pol + 1] = n;
  for(int i = 0; i < 2 * n; i++) printf("%d ", a[i]); printf("\n");
  return 0;
}