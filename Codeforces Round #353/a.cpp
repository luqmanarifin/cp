#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long d = b - a;
  if(d == 0) {
    puts("YES");
  } else if(c == 0) {
    puts("NO");
  } else if(d > 0 && c > 0 && d % c == 0) {
    puts("YES");
  } else if(d < 0 && c < 0 && d % c == 0) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}