#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int tot = abs(a) + abs(b);
  puts(tot <= c && tot % 2 == c % 2? "Yes" : "No");
  
  return 0;
}