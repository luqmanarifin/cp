#include <bits/stdc++.h>

using namespace std;

int a[] = {0, 1, 2, 4, 8, 16};
double p[] = {2, 1, 1./2, 1./4, 1./8, 1./16};

const int N = 5005;

int main() {
  int n, v;
  scanf("%d", &n);
  double ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    for (int j = 0; j < 6; j++) {
      if (v == a[j]) ans += p[j];
    }
  }
  printf("%.15f\n", ans);
  return 0;
}
