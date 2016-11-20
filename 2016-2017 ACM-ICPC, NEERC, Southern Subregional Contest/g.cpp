#include <bits/stdc++.h>

using namespace std;

set<pair<long long, long long>> s;

long long ada(int l, int r) {
  auto it = s.lower_bound(make_pair(l, -1));
  if (it != s.begin()) it--;
  long long pol = -1;
  while (it != s.end() && it->first <= r) {
    if (it->second >= l) {
      pol = max(pol, it->second);
    }
    it++;
  }
  return pol;
}

void insert(int l, int r) {
  s.insert(make_pair(l, r));
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (ada(a, a + b - 1) == -1) {
      insert(a, a + b - 1);
      printf("%d %d\n", a, a + b - 1);
    } else {
      int now = 1;
      while (ada(now, now + b - 1) != -1) {
        //printf("now %d\n", now);
        now = ada(now, now + b - 1) + 1;
      }
      insert(now, now + b - 1);
      printf("%d %d\n", now, now + b - 1);
    }
  }
  return 0;
}
