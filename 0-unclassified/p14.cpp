#include <bits/stdc++.h>

using namespace std;

int sum, got;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    got += a;
  }
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    sum += a;
  }
  int f;
  scanf("%d", &f);
  sum += f;
  for(int i = 0; i <= f; i++) {
    if(100 * (got + i) >= 65 * sum) {
      cout << i << endl;
      return 0;
    }
  }
  puts("-1");
  return 0;
}
