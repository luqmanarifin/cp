#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
deque<int> a;

int main() {
  int n;
  scanf("%d %s", &n, s);
  a.push_back(1);
  for(int i = 0; i < n - 1; i++) {
    if((i % 2 == 0 && s[i] == 'B') || (i % 2 && s[i] == 'A')) {
      a.push_back(i + 2);
    } else {
      a.push_front(i + 2);
    }
  }
  for(auto it : a) printf("%d ", it); printf("\n");
  return 0;
}
