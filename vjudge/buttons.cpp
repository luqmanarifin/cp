#include <bits/stdc++.h>

using namespace std;

// N, M
// transform dari N -> M
// N = N - 1
// N = N * 2

const int N = 1e4 + 5;
const int inf = 1e9;

int d[N];
int n, m;

bool valid(int x) {
  return 0 < x && x < N;
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < N; i++) {
    d[i] = inf;
  }
  queue<int> q;
  
  // inisialisasi queue
  d[n] = 0;
  q.push(n);
  
  // bfs
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    
    // pencet tombol -1
    int x = now - 1;
    if (valid(x) && d[x] == inf) {
      d[x] = d[now] + 1;
      q.push(x);
    }
    
    // pencet tombol *2
    x = now * 2;
    if (valid(x) && d[x] == inf) {
      d[x] = d[now] + 1;
      q.push(x);
    }
  }
  cout << d[m] << endl;

  return 0;
}
