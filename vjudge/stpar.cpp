#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    stack<int> s;
    int now = 1;
    for (int i = 0; i < n; i++) {
      s.push(a[i]);
      while (!s.empty() && s.top() == now) {
        s.pop();
        now++;
      }
    }
    puts(s.empty()? "yes" : "no");
  }
  return 0;
}
