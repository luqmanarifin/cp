#include <bits/stdc++.h>

using namespace std;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp;
  if (b & 1) tmp = tmp * a;
  return tmp;
}

const int N = 10;

int a[N];
long long now[N];

int main() {
  long long to = power(N, N);
  long long ans = 0;
  for (long long h = 0; h < to; h++) {
    long long v = h;
    for (int i = 0; i < N; i++) {
      a[i] = v % N;
      v /= N;
    }
    memset(now, 0, sizeof(now));
    for (int t = 0; t < N; t++) {
      for (int i = 1; i < N; i++) {
        now[i - 1] += now[i];
      }
      now[a[t]]++;
    }
    ans = max(ans, now[0]);
  }
  cout << ans << endl;
  return 0;
}
