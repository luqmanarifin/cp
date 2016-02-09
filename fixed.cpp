#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int i, j, n;
  scanf("%d", &n);
  int fix = 0;
  for(i = 0; i < n; i++) {
    scanf("%d", a + i);
    if(a[i] == i) fix++;
  }
  for(i = 0; i < n; i++) {
    if(a[i] != i) {
      if(a[a[i]] == i) {
        cout << fix + 2 << endl;
        return 0;
      }
    }
  }
  cout << min(n, fix + 1) << endl;
  return 0;
}