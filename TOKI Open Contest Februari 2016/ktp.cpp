#include <bits/stdc++.h>

using namespace std;

const int N = 10;

long long a[N];
long long d[N];
pair<long long, int> v[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  for(int i = 0; i < n; i++) {
    d[i] = a[(i + 1) % n] - a[i];
    v[i].second = i;
  }
  if(n == 5) {
    for(int i = 0; i < 5; i++) {
      if(i) printf(" ");
      printf("%d", i);
    }
    printf("\n");
    return 0;
  }
  int p = 0;
  while((p + 5) % n != 0) {
    int t = (p + 5) % n;
    v[t].first = v[p].first + d[p];
    p = t;
  }
  sort(v, v + n);
  for(int i = 0; i < 5; i++) {
    if(i) printf(" ");
    printf("%d", v[i].second);
  }
  printf("\n");
  return 0;
}
