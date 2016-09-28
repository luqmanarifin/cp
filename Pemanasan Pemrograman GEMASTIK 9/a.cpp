#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long v = 0;
    while (n--) {
      int a;
      scanf("%d", &a);
      v += a;
    }
    cout << v << endl;
  }

  return 0;
}
