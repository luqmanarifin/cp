#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int pmax = 0;
  for(int i = 1; i < n; i++) {
    if(a[i] > a[pmax]) {
      pmax = i;
    }
  }
  int pmin = n - 1;
  for(int i = n - 2; i >= 0; i--) {
    if(a[i] < a[pmin]) {
      pmin = i;
    }
  }
  int ret = abs(pmax - 0) + abs(n - 1 - pmin);
  if(pmin < pmax) ret--;
  cout << ret << endl;
  return 0;
}
