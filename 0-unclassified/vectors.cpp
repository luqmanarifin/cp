#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long double PI = (long double) acos(-1.0);

pair<long double, int> a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[i] = {(long double) atan2(v, u), i};
    //printf("%.18lf\n", a[i].first);
  }
  sort(a, a + n);
  long double ans = 1e9;
  int p = -1;
  for(int i = 0; i < n; i++) {
    long double dif = abs(a[(i+1)%n].first - a[i].first);
    dif = min(dif, 2*PI - dif);
    if(dif < ans) {
      ans = dif;
      p = i;
    }
  }
  int ai = a[p].second + 1;
  int aj = a[(p+1)%n].second + 1;
  printf("%d %d\n", ai, aj);
  return 0;
}