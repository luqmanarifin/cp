#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long t[N], d[N], ans[N];

int main() {
  int n, b;
  scanf("%d %d", &n, &b);
  for(int i = 0; i < n; i++) {
    scanf("%I64d %I64d", t + i, d + i);
  }
  deque<long long> q;
  for(int i = 0; i < n; i++) {
    while(q.size() && q.front() <= t[i]) q.pop_front();
    if(q.size() >= b + 1) {
      ans[i] = -1;
      continue;
    }
    long long st = max(t[i], q.size()? q.back() : 0LL);
    ans[i] = st + d[i];
    //printf("%d start %I64d finish %I64d\n", i, st, ans[i]);
    q.push_back(ans[i]);
  }
  for(int i = 0; i < n; i++) printf("%I64d ", ans[i]);
  return 0;
}
