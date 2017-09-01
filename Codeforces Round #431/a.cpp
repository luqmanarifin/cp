#include <bits/stdc++.h>

using namespace std;

long long f(int n) {
  return 1LL * n * (n - 1) / 2;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<char> ans;
  int c = 0;
  while (1) {
    int at = -1;
    for (int i = 1; ; i++) {
      if (f(i) <= n) {
        at = i;
      } else {
        break;
      }
    }
    for (int i = 0; i < at; i++) {
      ans.push_back(c + 'a');
    }
    n -= f(at);
    c++;
    if (n == 0) break;
  }
  for (auto it : ans) printf("%c", it); printf("\n");
  return 0;
}