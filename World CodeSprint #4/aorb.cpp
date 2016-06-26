#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

bool a[N], b[N], c[N];
char sa[N], sb[N], sc[N];

void print(int k) {
  if(k < 10) printf("%d", k);
  else printf("%c", k - 10 + 'A');
}

int val(char c) {
  if('0' <= c && c <= '9') return c - '0';
  else return c - 'A' + 10;
}

void flush(char* s, bool* p) {
  int n = strlen(s);
  for(int i = n - 1; i >= 0; i--) {
    int v = val(s[i]);
    int at = n - 1 - i;
    for(int j = 0; j < 4; j++) {
      p[at * 4 + j] = v % 2;
      v /= 2;
    }
  }
}

void print(bool* p, int n) {
  int n4 = n / 4;
  bool ada = 0;
  for(int i = n4 - 1; i >= 0; i--) {
    int v = 0;
    for(int j = 3; j >= 0; j--) {
      v = v * 2 + p[i * 4 + j];
    }
    if(ada == 0 && v == 0) continue;
    ada = 1;
    print(v);
  }
  if(ada == 0) printf("0");
  printf("\n");
}

int main() {
  int q;
  scanf("%d", &q);
  while(q--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(sa, 0, sizeof(sa));
    memset(sb, 0, sizeof(sb));
    memset(sc, 0, sizeof(sc));
    
    int k;
    scanf("%d %s %s %s", &k, sa, sb, sc);
    int na = strlen(sa) * 4;
    int nb = strlen(sb) * 4;
    int nc = strlen(sc) * 4;
    flush(sa, a);
    flush(sb, b);
    flush(sc, c);
    int n = max(na, max(nb, nc));
    int need = 0;
    for(int i = 0; i < n; i++) {
      if(c[i] == 0) {
        need += a[i] + b[i];
      } else {
        need += (a[i] == 0 && b[i] == 0);
      }
    }
    if(need > k) {
      puts("-1");
      continue;
    }
    for(int i = n - 1; i >= 0; i--) {
      if(c[i] == 0) {
        k -= a[i] + b[i];
        a[i] = 0;
        b[i] = 0;
      } else {
        if(a[i] == 0 && b[i] == 0) {
          k--;
          b[i] = 1;
        }
      }
    }
    assert(k >= 0);
    for(int i = n - 1; i >= 0; i--) {
      if(c[i] == 1) {
        if(a[i] && b[i]) {
          if(k) {
            k--;
            a[i] = 0;
          }
        } else if(a[i] && b[i] == 0) {
          if(k >= 2) {
            k -= 2;
            a[i] = 0;
            b[i] = 1;
          }
        }
      }
    }
    assert(k >= 0);
    print(a, n);
    print(b, n);
  }

  return 0;
}
