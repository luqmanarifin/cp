#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> p;
bool is[N];
long long dp[N];

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  for (int i = 1; i < p.size(); i++) {
    p[i] += p[i - 1];
  } 
  for (int i = 0; i < p.size(); i++) {
    for (int j = i; j < p.size(); j++) {
      int num = p[j] - (i? p[i - 1] : 0);
      if (num < N) {
        dp[num]++;
      }
    }
  }
 
  int n;
  while (scanf("%d", &n) && n) {
    printf("%I64d\n", dp[n]);
  }
  return 0;
}
