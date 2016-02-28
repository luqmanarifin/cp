#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 10;

int p, n, x;

int front() { 
  int col = x / p;
  int ret = col + (x - col * p);
  if((col + 1) * p <= n) {
    ret = min(ret, col + 1 + ((col + 1) * p - x));
  }
  return ret;
}

int back() {
  int col = x / p;
  int pol = n / p;
  int at = n % p;
  int c = pol + (pol*p != n? 1 : 0);
  int ret = abs(col*p + at - x) + c + abs(pol - col);
  if(col > 0) {
    ret = min(ret, abs((col-1)*p + at - x) + c + abs(pol - (col - 1)));
  }
  if(col < pol) {
    ret = min(ret, abs((col+1)*p + at - x) + c + abs(pol - (col + 1)));
  }
  return ret;
}

int main() {
  scanf("%d %d %d", &p, &n, &x);
  printf("%d\n", min(front(), back()));
  return 0;
}
 