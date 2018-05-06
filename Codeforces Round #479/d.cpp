#include <bits/stdc++.h>

using namespace std;

const long long inf = 4e18;
const int N = 105;

long long a[N];
map<long long, int> id;
int ke[N], ada[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    id[a[i]] = i;
  }
  memset(ke, -1, sizeof(ke));
  for (int i = 0; i < n; i++) {
    if (a[i] % 3 == 0 && id.count(a[i] / 3)) {
      ke[i] = id[a[i] / 3];
      ada[id[a[i] / 3]] = 1;
    }
    if (inf / a[i] >= 2 && id.count(a[i] * 2)) {
      ke[i] = id[a[i] * 2];
      ada[id[a[i] * 2]] = 1;
    }
  }
  for (int i = 0; i < n; i++) if (ada[i] == 0) {
    for (int it = 0; it < n; it++) {
      printf("%lld ", a[i]);
      i = ke[i];
    }
    return 0;
  }

  return 0;
}
