#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const long long inf = 1e18;

bool is[N];
vector<int> p;

int main() {
  int prime = 0;
  long long all = 1;
  int cok = 0;
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      all *= i;
      //assert(all > 0 && all < inf);
      cok++;
      cout << cok << " " << all << endl;
      for (int j = i * i; j < N; j += i) is[j] = 1;
    }
  }
  int ada = 0;
  for (int mask = 0; mask < (1 << p.size()); mask++) {
    long long now = 1;
    for (int i = 0; i < p.size(); i++) {
      if (mask & (1 << i)) {
        long long lim = inf / now;
        if (p[i] > lim) {
          now = inf;
          break;
        }
        now *= p[i];
      }
    }
    if (now == inf) continue;
    ada++;
  }
  cout << ada << endl;
  return 0;
}
