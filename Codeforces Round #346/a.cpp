#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  a--;
  a += b;
  a %= n;
  if(a < 0) a += n;
  cout << a + 1 << endl;
  return 0;
}
