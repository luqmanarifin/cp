
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] <= now + 'a') {
      s[i] = now + 'a';
      now++;
      if (now == 26) break;
    }
  }
  if (now == 26) {
    cout << s << endl;
  } else {
    puts("-1");
  }
  return 0;
}
