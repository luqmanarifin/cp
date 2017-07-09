#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e8;

int s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < N; i++) s[i] = inf;
    
    priority_queue<pair<int, int> > q;
    s[a] = 0;
    q.push(make_pair(0, a));
    while (!q.empty()) {
      pair<int, int> p = q.top();
      int now = p.second;
      q.pop();
      if (now + 1 < N && s[now] + 1 < s[now + 1]) {
        s[now + 1] = s[now] + 1;
        q.push(make_pair(-s[now + 1], now + 1));
      }
      if (now - 1 >= 0 && s[now] + 1 < s[now - 1]) {
        s[now - 1] = s[now] + 1;
        q.push(make_pair(-s[now - 1], now - 1));
      }
      if (now * 2 < N && s[now] + 2 < s[now * 2]) {
        s[now * 2] = s[now] + 2;
        q.push(make_pair(-s[now * 2], now * 2));
      }
      if (now % 2 == 0 && s[now] + 2 < s[now / 2]) {
        s[now / 2] = s[now] + 2;
        q.push(make_pair(-s[now / 2], now / 2));
      }
      if (now * 3 < N && s[now] + 3 < s[now * 3]) {
        s[now * 3] = s[now] + 3;
        q.push(make_pair(-s[now * 3], now * 3));
      }
      if (now % 3 == 0 && s[now] + 3 < s[now / 3]) {
        s[now / 3] = s[now] + 3;
        q.push(make_pair(-s[now / 3], now / 3));
      }
    }
    printf("%d\n", s[b]);
  }

  return 0;
}
