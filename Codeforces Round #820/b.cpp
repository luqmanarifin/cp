#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    vector<char> c;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        c.push_back('a' + (s[i-2] - '0') * 10 + (s[i-1] - '0') - 1);
        i -= 2;
      } else {
        c.push_back('a' + s[i] - '0' - 1);
      }
    }
    reverse(c.begin(), c.end());
    for (auto it : c) printf("%c", it); printf("\n");
  }

  return 0;
}
