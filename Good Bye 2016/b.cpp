#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int now = 0;
  while (n--) {
    int a;
    string b;
    cin >> a >> b;
    if (now == 0 && b != "South") {
      puts("NO");
      return 0;
    }
    if (now == 20000 && b != "North") {
      puts("NO");
      return 0;
    }
    if (b == "South") {
      now += a;
    } else if (b == "North") {
      now -= a;
    }
    if (now < 0 || now > 20000) {
      puts("NO");
      return 0;
    }
  }
  if (now != 0) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}
