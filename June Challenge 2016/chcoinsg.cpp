#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    puts(n % 6? "Chef" : "Misha");
  }
  return 0;
}