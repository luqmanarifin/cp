#include <bits/stdc++.h>

using namespace std;

int a[10];

int main() {
  int n = 10;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  reverse(a, a + n);
  cout << a[0] + a[2] + a[4] << endl;
  return 0;
}
