#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long inf = 4e18;
const long long lim = 1e9;

long long a[N], d[N], c[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    if(a[i] > 3 * lim) {
      puts("-1");
      return 0;
    }
    sum += a[i];
  }
  if(sum % 3) {
    puts("-1");
    return 0;
  }
  sum /= 3;
  if(n % 3) {
    for(int i = 0; i < n; i++) {
      d[i] = a[(i + 2) % n] - a[(i + 1) % n];
    }
    for(int i = 0; (i + 3) % n; i = (i + 3) % n) {
      c[(i + 3) % n] = c[i] + d[i];
    }
    if(c[n - 3] + d[n - 3] != c[0]) {
      puts("-1");
      return 0;
    }
    long long csum = 0, minc = inf, makc = -inf;
    for(int i = 0; i < n; i++) {
      csum += c[i];
      minc = min(minc, c[i]);
      makc = max(makc, c[i]);
    }
    sum -= csum;
    if(sum % n) {
      puts("-1");
      return 0;
    }
    long long p = sum / n;
    if(p + makc > lim || p - minc < -lim) {
      puts("-1");
      return 0;
    }
    for(int i = 0; i < n; i++) {
      printf("%I64d ", p + c[i]);
      assert(-lim <= p + c[i] && p + c[i] <= lim);
      long long sum = 0;
      for(int j = 0; j < 3; j++) {
        int at = (i + j) % n;
        sum += p + c[at];
      }
      assert(sum == a[(i + 1) % n]);
    }
    return 0;
  }
  for(int i = 0; i < n; i++) {
    d[i] = a[(i + 2) % n] - a[(i + 1) % n];
  }
  for(int j = 0; j < 3; j++) {
    for(int i = j; (i + 3) % n != j; i = (i + 3) % n) {
      c[(i + 3) % n] = c[i] + d[i];
    }
    if(c[n + j - 3] + d[n + j - 3] != c[j]) {
      puts("-1");
      return 0;
    }
  }
  long long makc[3], minc[3], p[3], csum = 0;
  for(int j = 0; j < 3; j++) {
    makc[j] = -inf;
    minc[j] = inf;
    p[j] = 0;
  }
  for(int i = 0; i < n; i++) {
    int j = i % 3;
    makc[j] = max(makc[j], c[i]);
    minc[j] = min(minc[j], c[i]);
    csum += c[i];
  }
  for(int j = 0; j < 3; j++) {
    long long range = makc[j] - minc[j];
    if(range > 2 * lim) {
      puts("-1");
      return 0;
    }
  }
  
  sum -= csum;
  if(sum % (n / 3)) {
    puts("-1");
    return 0;
  }
  sum /= n / 3;
  for(int j = 0; j < 3; j++) {
    if(p[j] + makc[j] > lim) {
      long long dif = p[j] + makc[j] - lim;
      p[j] -= dif;
      sum += dif;
    }
    if(p[j] - minc[j] < -lim) {
      long long dif = -lim - (p[j] - minc[j]);
      p[j] += dif;
      sum -= dif;
    }
  }
  for(int j = 0; j < 3; j++) {
    if(sum > 0) {
      long long can = lim - (p[j] + makc[j]);
      long long dif = min(can, sum);
      sum -= dif;
      p[j] += dif;
    }
    if(sum < 0) {
      long long can = p[j] - minc[j] - (-lim);
      long long dif = min(can, -sum);
      sum += dif;
      p[j] -= dif;
    }
  }
  if(sum != 0) {
    puts("-1");
    return 0;
  }
  for(int i = 0; i < n; i++) {
    printf("%I64d ", p[i%3] + c[i]);
    assert(-lim <= p[i%3] + c[i] && p[i%3] + c[i] <= lim);
    long long sum = 0;
    for(int j = 0; j < 3; j++) {
      int at = (i + j) % n;
      sum += p[at%3] + c[at];
    }
    assert(sum == a[(i + 1) % n]);
  }
  return 0;
}
