#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int a, b;
    scanf("%d.%d", &a, &b);
    cout << a * 60 + b << endl;
  }
  
  return 0;
}
