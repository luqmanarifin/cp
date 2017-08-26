#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N];

int main() {
  int k;
  scanf("%s %d", s, &k);
  int n = strlen(s);
  set<char> all;
  for (int i = 0; i < n; i++) {
    all.insert(s[i]);
  }
  if (k > n) {
    puts("impossible");
  } else {
    printf("%d\n", max(0, k - (int) all.size()));
  }
  return 0;
}
