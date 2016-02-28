#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

double cur[N];
long long carry[N];
char s[N];

int main() {
  scanf("%s", &s[1]);
  int n = strlen(&s[1]);
  int vow = 0;
  for(int i = 1; i <= n; i++) {
    if(s[i] == 'I' || s[i] == 'E' || s[i] == 'A'
    || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
      cur[min(i, n - i + 1)]++;
      vow++;
    }
  }
  int to = n / 2 + n % 2;
  double ans = 0;
  for(int i = 1; i <= to; i++) {
    long long here = cur[i];
    cur[i] = vow + (double) carry[i - 1] / i;
    carry[i] = carry[i - 1] + here * i;
    vow -= here;
    ans += cur[i];
  }
  for(int i = to + 1; i <= n; i++) {
    cur[i] = cur[n - i + 1] * (double) (n - i + 1) / i;
    ans += cur[i];
  }
  printf("%.15lf\n", ans);
  return 0;
}