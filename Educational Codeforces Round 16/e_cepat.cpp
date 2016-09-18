#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 5;
const long long inf = 1e18;

long long d[N];
bool in[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);

  for (int i = 0; i < N; i++) d[i] = inf;
  queue<int> pq;
  d[0] = 0;
  in[0] = 1;
  pq.emplace(0);
  while (!pq.empty()) {
    int i = pq.front();
    long long cost = d[i];
    in[i] = 0;
    pq.pop();
    if (i + 1 < N) {
      if (cost + a < d[i + 1] && !in[i + 1]) {
        d[i + 1] = cost + a;
        pq.push(i + 1);
      }
    }
    if (i - 1 >= 0) {
      if (cost + a < d[i - 1] && !in[i - 1]) {
        d[i - 1] = cost + a;
        pq.push(i - 1);
      }
    }
    if (i * 2 < N) {
      if (cost + b < d[i * 2] && !in[i * 2]) {
        d[i * 2] = cost + b;
        pq.push(i * 2);
      }
    }
  }
  cout << d[n] << endl;
  return 0;
}
