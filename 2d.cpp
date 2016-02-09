#include <bits/stdc++.h>

using namespace std;

const int PRIME = 131;
const long long MOD = 1e9 + 9;
const int N = 1005;

char text[N][N];
char pattern[N][N];
long long pre[N][N];
long long val[N][N];
long long power[2 * N];

long long compute(int i, int j, int nlen, int mlen) {
  int ci = i + nlen - 1;
  int cj = j + mlen - 1;
  long long ret = pre[ci][cj];
  ret -= pre[i - 1][cj] * power[nlen];
  ret -= pre[ci][j - 1] * power[mlen];
  ret += pre[i - 1][j - 1] * power[nlen + mlen];
  ret %= MOD;
  if(ret < 0) {
    ret += MOD;
  }
  return ret;
}

int main() {
  clock_t ct = clock();
  power[0] = 1;
  for(int i = 1; i < 2 * N; i++) {
    power[i] = power[i - 1] * PRIME;
    power[i] %= MOD;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%s", &text[i][1]);
    for(int j = 1; j <= m; j++) {
      pre[i][j] = text[i][j];
      pre[i][j] += pre[i - 1][j] * PRIME;
      pre[i][j] += pre[i][j - 1] * PRIME;
      pre[i][j] -= pre[i - 1][j - 1] * power[2];
      pre[i][j] %= MOD;
      if(pre[i][j] < 0) {
        pre[i][j] += MOD;
      }
    }
  }
  puts("Text read");
  int n2, m2;
  scanf("%d %d", &n2, &m2);
  for(int i = 1; i <= n2; i++) {
    scanf("%s", &pattern[i][1]);
    for(int j = 1; j <= m2; j++) {
      val[i][j] = pattern[i][j];
      val[i][j] += val[i - 1][j] * PRIME;
      val[i][j] += val[i][j - 1] * PRIME;
      val[i][j] -= val[i - 1][j - 1] * power[2];
      val[i][j] %= MOD;
      if(val[i][j] < 0) {
        val[i][j] += MOD;
      }
    }
  }
  puts("Pattern read");
  bool found = 0;
  for(int i = 1; i + n2 <= n + 1; i++) {
    for(int j = 1; j + m2 <= m + 1; j++) {
      if(compute(i, j, n2, m2) == val[n2][m2]) {
        printf("Found at %d %d\n", i, j);
        found = 1;
      }
    }
  }
  if(!found) {
    puts("Pattern not found");
  }
  ct = clock() - ct;
  printf ("It took me (%lf seconds).\n", ((double)ct)/CLOCKS_PER_SEC);
  return 0;
}
