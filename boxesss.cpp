#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if(a > b) swap(a, b);
  if(c > d) swap(c, d);
  puts((a <= c && b <= d) || (a >= c && b >= d)? "Yes" : "No");
  return 0;
}
