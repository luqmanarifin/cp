#include <bits/stdc++.h>

using namespace std;

int x[1005], y[1005];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  } 
  int d = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      d = max(d, abs(x[i] - x[j]));
      d = max(d, abs(y[i] - y[j]));
    }
  }
  cout << (long long) d * d << endl;
  return 0;
}