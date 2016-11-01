#include <bits/stdc++.h>

using namespace std;

const int N = 105;

const char c[] = { 'A', 'E', 'I', 'O', 'U', 'Y'};

char s[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  vector<int> a;
  a.push_back(0);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      if (s[i] == c[j]) {
        a.push_back(i);
        break;
      }
    }
  }
  a.push_back(n + 1);
  int ans = 0;
  for (int i = 1; i < a.size(); i++) {
    ans = max(ans, a[i] - a[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
