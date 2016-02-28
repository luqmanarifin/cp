#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long inf = 1e18;

int rmq[N][21];
int a[N], n;
char s[N];

// tanah = genap, kalo ganjil berarti miring
void build() {
  for(int i = 0; i < n; i++) {
    rmq[i][0] = a[i];
  }
  for(int j = 1; (1 << j) <= n; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1<<(j-1))][j - 1]);
    }
  }
}

int find(int l, int r) {
  int c = __builtin_clz(r - l + 1) ^ 31;
  return min(rmq[l][c], rmq[r-(1<<c)+1][c]);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int m;
    scanf("%d %d %s", &n, &m, s);
    int now = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '/') {
        now++;
      } else if(s[i] == '\\') {
        now--;
      }
      a[i] = now;
      //printf("%d ", a[i]);
      if(s[i] == '/') {
        now++;
      } else if(s[i] == '\\') {
        now--;
      }
    }
    //printf("\n");
    build();
    int h = find(0, m - 1);
    if(h % 2) h--;
    long long cur = 0;
    for(int i = 0; i < m; i++) {
      cur += a[i] - h;
    }
    //printf("jadi %d : butuh %d\n", h, cur);
    long long ans = cur;
    for(int i = 1; i + m <= n; i++) {
      cur += a[i + m - 1] - h;
      cur -= a[i - 1] - h;
      int hnew = find(i, i + m - 1);
      if(hnew % 2) hnew--;
      cur += 1LL * (h - hnew) * m;
      h = hnew;
      ans = min(ans, cur);
      //printf("jadi %d : butuh %d\n", h, cur);
    }
    printf("Case #%d: %.1f\n", tt, (double) ans / 2);
  }
  
  return 0;
}
