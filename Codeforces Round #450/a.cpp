
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a = 0, b = 0;
  while (n--) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u < 0) a++;
    else b++;
  }
  puts(a <= 1 || b <= 1? "Yes" : "No");
  return 0;
}
