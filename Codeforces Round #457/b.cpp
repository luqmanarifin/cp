#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n; int k;
  scanf("%I64d %d", &n, &k);
  priority_queue<int> pq;
  for (int i = 0; i <= 62; i++) {
    if (n & (1LL << i)) {
      pq.push(i);
    }
  }
  if (pq.size() > k) {
    puts("No");
    return 0;
  }
  puts("Yes");
  while (pq.size() < k) {
    int now = pq.top();
    pq.pop();
    pq.push(now - 1);
    pq.push(now - 1);
  }
  while (pq.size()) {
    printf("%d ", pq.top());
    pq.pop();
  }

  return 0;
}
