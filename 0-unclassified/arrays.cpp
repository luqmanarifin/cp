#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int b[N];

int main() {
  int na, nb;
  int k, m;
  scanf("%d %d %d %d", &na, &nb, &k, &m);
  for(int i = 0; i < na; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < nb; i++) {
    scanf("%d", b + i);
  }
  puts(a[k - 1] < b[nb - m]? "YES" : "NO");
  return 0;
}
