#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 5;
const long long inf = 1e11;

const int N = 5e7;

bitset<N> is;

bool isPrime(long long num) {
  assert(num < N);
  if(num == 2) return 1;
  if(num % 2 == 0) return 0;
  return !is[num];
}

int a[M];

int main() {
  for(int i = 3; 1LL * i * i <= N; i++) {
    if(!is[i]) {
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }

  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    long long sum = 0, mini = inf;
    for(int i = 0; i < n; i++) {
      if(a[i] < 2) {
        puts("-1");
        goto next;
      }
      sum += a[i];
      mini = min(mini, 1LL * a[i] - 2);
    }
    cout << sum - mini << endl;
    next:;
  }
  return 0;
}
