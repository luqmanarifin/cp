#include <bits/stdc++.h>

using namespace std;

long long get(int n, char s[77]) {
  bool rev = 0;
  long long now = 0;
  for (int i = 0; i < n; i++) {
    if (rev) {
      if (s[i] == '0')
        now += 1LL << (n-i-1);
    }
    else {
      if (s[i] == '1')
        now += 1LL << (n-i-1);
    }
    rev ^= s[i] == '1';
  }
  return now;
}

int n;
char a[77], b[77];


int main() {
  scanf("%d", &n);
  scanf("%s %s", a, b);
  cout << get(n, b) - get(n, a) - 1 << endl;
  return 0;
}
