#include <bits/stdc++.h>

using namespace std;

const int N = 200;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  n = strlen(s);
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      pos.push_back(i);
    }
  }
  int last = -1;
  for (auto it : pos) {
    printf("%d", it - last - 1);
    last = it;
  }
  printf("%d\n", n - last - 1);
  return 0;
}
