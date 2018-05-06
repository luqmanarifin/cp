
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    int j = a[i];
    int k = a[j];
    if (i == a[k]) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
