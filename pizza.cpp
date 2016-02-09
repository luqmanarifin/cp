#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.);
const int N = 360 * 60 * 60 + 5;

bool done[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int r, n, j, m, d;
    scanf("%d %d %d %d %d", &r, &n, &j, &m, &d);
    int all = 360 * 60 * 60;
    int lom = 60 * 60 * j  + 60 * m + d;
    memset(done, 0, sizeof(done));
    int now = 0;
    for(int i = 0; i < n; i++) {
      if(done[now]) break;
      done[now] = 1;
      now = (now + lom) % all;
    }
    int bef = 0;
    int maxi = 0;
    for(int i = 1; i < all; i++) {
      if(done[i]) {
        maxi = max(maxi, i - bef);
        bef = i;
      }
    }
    maxi = max(maxi, all - bef);
    double L = pi * r * r;
    //cout << L << endl;
    printf("%.15f\n", L * maxi / all);
  }
  return 0;
}
