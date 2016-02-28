#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int at = n - 1;
  for(int i = n - 2; i >= 0; i--) {
    if(a[i] == a[i + 1]) {
      at = i;
    } else {
      break;
    }
  }
  if(k <= at) {
    puts("-1");
  } else {
    cout << at << endl;
  }
  
  return 0;
}
