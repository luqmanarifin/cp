#include <bits/stdc++.h>

using namespace std;

void cok(string s) {
  int sum = 0;
  for(int i = 0; i < s.size(); i++) {
    if(i) printf("+");
    printf("%d", s[i] - 'a' + 1);
    sum += s[i] - 'a' + 1;
  }
  printf(" = %d\n", sum);
}

int main() {
  cok("laziness");
  cok("procrastination");
  return 0;
}
