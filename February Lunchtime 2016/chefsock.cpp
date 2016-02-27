#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  puts(((c - a) / b) % 2? "Unlucky Chef" : "Lucky Chef");
  return 0;
}
