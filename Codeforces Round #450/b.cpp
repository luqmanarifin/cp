
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool done[N];

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int cnt = 0;
  while (!done[a]) {
    done[a] = 1;
    cnt++;
    int now = a * 10 / b;
    if (now == c) {
      cout << cnt << endl;
      return 0;
    }
    a = a * 10 % b;
  }
  puts("-1");
  return 0;
}
