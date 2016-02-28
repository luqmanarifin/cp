#include <bits/stdc++.h>

using namespace std;

char s[100];

int main() {
  int n;
  scanf("%d %s", &n, s);
  long long a = 1, b = 0;
  for(int i = n - 1; i >= 0; i--) {
    long long ta = a, tb = b;
    a = -a; b = -b;
    if(s[i] == 'U') {
      swap(a, b);
      b = -b;
    } else {
      swap(a, b);
      a = -a;
    }
    a += ta;
    b += tb;
  }
  cout << a << ' ' << b << endl;
  return 0;
}
