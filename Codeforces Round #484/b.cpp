#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int w[N];
char s[N];

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<pair<int, int>> in, ex;
  for (int i = 1; i <= n; i++) {
    scanf("%d", w + i);
    in.emplace(-w[i], i);
  }
  scanf("%s", s);
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '0') {
      auto it = in.top();
      in.pop();
      ex.emplace(-it.first, it.second);
      printf("%d ", it.second);
    } else {
      auto it = ex.top();
      ex.pop();
      printf("%d ", it.second);
    }
  }


  return 0;
}
