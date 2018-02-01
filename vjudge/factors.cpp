#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool is[N];
int last[N];
vector<int> p;

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      last[i] = i;
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
        last[j] = i;
      }
    }
  }
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;
    int ori = n;
    set<int> prime;
    while (n != 1) {
      prime.insert(last[n]);
      n /= last[n];
    }
    printf("%d : %d\n", ori, prime.size());
  }

  return 0;
}
