#include <bits/stdc++.h>

using namespace std;

int main() {
  deque<char> d;
  int q;
  scanf("%d", &q);
  while (q--) {
    int t;
    char c;
    scanf("%d %c", &t, &c);
    if (t == 0) {
      d.push_front(c);
    } else {
      d.push_back(c);
    }
  }
  while (!d.empty()) {
    printf("%c", d.front());
    d.pop_front();
  }
  printf("\n");
  return 0;
}