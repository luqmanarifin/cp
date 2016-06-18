#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], p[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    p[a[i]] = i;
  }
  int last = -1, best = 0;
  int cur = 0;
  for(int i = 1; i <= n; i++) {
    if(p[i] > last) {
      last = p[i];
      cur++;
    } else {
      break;
    }
  }
  best = max(best, cur);
  
  cur = 0; last = n + 1;
  for(int i = n; i >= 1; i--) {
    if(p[i] < last) {
      last = p[i];
      cur++;
    } else {
      break;
    }
  }
  best = max(best, cur);
  cout << n - best << endl;
  return 0;
}
