#include <bits/stdc++.h>

using namespace std;

int di[] = {1, 1, -1, -1, 0, 0, 1, -1};
int dj[] = {1, -1, 1, -1, 1, -1, 0, 0};

char s[5];

int main() {
  scanf("%s", s);
  int a = s[0] - 'a';
  int b = s[1] - '1';
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    int ti = a + di[i];
    int tj = b + dj[i];
    if (0 <= ti && ti < 8 && 0 <= tj && tj < 8) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
