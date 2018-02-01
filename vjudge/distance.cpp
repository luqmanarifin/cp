#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool is[N];
vector<int> p;

bool mrtest(long long n) {
  for (auto it : p) {
    if (1LL * it * it > n) break;
    if (n % it == 0) return 0;
  }
  return 1;
}

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int l, u;
  while (scanf("%d %d", &l, &u) == 2) {
    int ada = 0, a, b, c, d;
    long long maxi = -1e18, mini = 1e18;
    int last = -1;
    for (int i = l; i <= u; i++) {
      if (mrtest(i)) {
        //printf("%d\n", i);
        if (last == -1) {
          last = i;
          continue;
        }
        ada = 1;
        int dist = i - last;
        if (dist < mini) {
          mini = dist;
          a = last;
          b = i;
        }
        if (dist > maxi) {
          maxi = dist;
          c = last;
          d = i;
        }
        
        last = i;
      }
    }
    if (ada) {
      printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
    } else {
      puts("There are no adjacent primes.");
    }
  }
  return 0;
}
