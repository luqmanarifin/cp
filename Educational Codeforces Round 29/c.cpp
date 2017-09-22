#include <bits/stdc++.h>

using namespace std;

int a[3][3], b[3][3];

// u win v -> 1
// v win u -> -1
int score(int u, int v) {
  if ((v + 1) % 3 == u) return 1;
  if ((u + 1) % 3 == v) return -1;
  return 0;
}

int dp[3][3];
int ua[20], ub[20];

int main() {
  long long k;
  int A, B;
  scanf("%lld %d %d", &k, &A, &B);
  A--;
  B--;
  int oriA = A;
  int oriB = B;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &b[i][j]);
      b[i][j]--;
    }
  }
  memset(dp, -1, sizeof(dp));
  int now = 0;
  while (dp[A][B] == -1) {
    //printf("kokoro %d %d\n", A, B);
    dp[A][B] = now;
    ua[now] = A;
    ub[now] = B;
    int ta = a[A][B];
    int tb = b[A][B];
    A = ta;
    B = tb;
    now++;
  }
  int K = dp[A][B];
  int offset = now;

  int cyc = now - dp[A][B];
  long long sa = 0;
  long long sb = 0;
  if (k <= now) {
    A = oriA;
    B = oriB;
    for (int i = 0; i < k; i++) {
      if (score(A, B) == 1) {
        sa++;
      } else if (score(A, B) == -1) {
        sb++;
      }
      int ta = a[A][B];
      int tb = b[A][B];
      A = ta;
      B = tb;
    }
  } else {
    long long kali = (k - offset) / cyc;
    long long rem = k - (offset + kali * cyc);

    //printf("kali %lld rem %lld offset %d\n", kali, rem, offset);
    //printf("cyc %d\n", cyc);

    A = oriA;
    B = oriB;
    for (int i = 0; i < now; i++) {
      //printf("cibai %d %d\n", A, B);
      if (score(A, B) == 1) {
        sa++;
      } else if (score(A, B) == -1) {
        sb++;
      }
      int ta = a[A][B];
      int tb = b[A][B];
      A = ta;
      B = tb;
    }
    //printf("sa sb %lld %lld\n", sa, sb);

    A = ua[K];
    B = ub[K];
    long long ca = 0, cb = 0;
    for (int i = K; i < now; i++) {
      if (score(A, B) == 1) {
        ca++;
      } else if (score(A, B) == -1) {
        cb++;
      }
      int ta = a[A][B];
      int tb = b[A][B];
      A = ta;
      B = tb;
    }
    sa += kali * ca;
    sb += kali * cb;

    A = ua[K];
    B = ub[K];
    for (int i = K; i < K + rem; i++) {
      if (score(A, B) == 1) {
        sa++;
      } else if (score(A, B) == -1) {
        sb++;
      }
      int ta = a[A][B];
      int tb = b[A][B];
      A = ta;
      B = tb;
    }
  }
  printf("%lld %lld\n", sa, sb);
  return 0;
}