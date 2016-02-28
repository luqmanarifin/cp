#include <bits/stdc++.h>

using namespace std;

char cuk[] = "PER";

const int N = 305;
char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += s[i] != cuk[i % 3];
  }
  cout << ans << endl;
  return 0;
}
