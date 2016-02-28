#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int num[N];
int q[N][2];

int get(int at) {
  return num[at] * (q[at][0] + q[at][1]);
}

void push(int at, int val) {
  if(num[at] == 0) {
    num[at]++;
    q[at][0] = q[at][1] = val;
    return;
  }
  num[at]++;
  q[at][0] = q[at][1];
  q[at][1] = val;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  priority_queue<pair<int, int>> pq;
  for(int i = 1; i <= k; i++) {
    pq.emplace(0, -i);
  }
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    while(-pq.top().first != get(-pq.top().second)) {
      pq.pop();
    }
    int at = -pq.top().second;
    pq.pop();
    printf("%d ", at);
    push(at, a);
    pq.emplace(-get(at) ,-at);
  }
  printf("\n");
  return 0;
}
