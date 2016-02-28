#include <bits/stdc++.h>

using namespace std;

long long sum(long long num) {
  return num * (num + 1) / 2;
}

long long square(long long num) {
  return num * (num + 1) * (2 * num + 1) / 6;
}

long long solvedatar(long long n, long long m) {
  long long to = min(m, n / 2);
  if(to == 0) {
    return 0;
  }
  long long ret = (n*m + n + m + 1) * to;
  ret += (n + 2*m + 2) * -sum(to);
  ret += square(to);
  return ret;
}

long long solvediag(long long n, long long m) {
  long long to = min(m / 2, n / 2);
  if(to == 0) {
    return 0;
  }
  long long ret = (n*m + n + m + 1) * to;
  ret += (n + m + 2) * (-2 * sum(to));
  ret += 4 * square(to);
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", 2 * (solvedatar(n, m) + solvedatar(m, n) + 2 * solvediag(n, m)));
  }
  return 0;
}
