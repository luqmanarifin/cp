#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

char s[20];
int a[N];
bool ada[N];

int len[N];

int main() {
  int n;
  scanf("%s %d", s, &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int l = 0, r = 0;
  for(int i = 1; i <= n; i++) {
    ada[a[i - 1]] = 0;
    if(r < i) {
      ada[a[i]] = 1;
      r = i;
    }
    while(r + 1 <= n && !ada[a[r + 1]]) {
      ada[a[r + 1]] = 1;
      r++;
    }
    len[i] = r - i + 1;
  }
  //for(int i = 1; i <= n; i++) printf("%d ", len[i]); printf("\n");
  l = 1; r = n / 2;
  while(l < r) {
    int mid = (l + r + 1) >> 1;
    int p = -1, q = -1;
    for(int i = 1; i <= n; i++) {
      if(len[i] >= mid) {
        p = i;
        break;
      }
    }
    for(int i = n; i >= 1; i--) {
      if(len[i] >= mid) {
        q = i;
        break;
      }
    }
    if(p == -1) {
      r = mid - 1;
    } else {
      if(p + mid <= q) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
  }
  int p = -1, q = -1;
  for(int i = 1; i <= n; i++) {
    if(len[i] >= l) {
      p = i;
      break;
    }
  }
  for(int i = n; i >= 1; i--) {
    if(len[i] >= l) {
      q = i;
      break;
    }
  }
  printf("%d %d %d %d\n", p, p + l - 1, q, q + l - 1);
  return 0;
}