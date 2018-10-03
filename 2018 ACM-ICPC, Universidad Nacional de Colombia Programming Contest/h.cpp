#include <bits/stdc++.h>

using namespace std;

bool leap(int n) {
  if (n % 400 == 0) return 1;
  if (n % 100 == 0) return 0;
  if (n % 4 == 0) return 1;
  return 0;
}

string names[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
  int n;
  cin >> n;
  int now = 0, ans = 6;
  while (now < n) {
    if (leap(now + 1868)) {
      ans += 366;
    } else {
      ans += 365;
    }
    now++;
    ans %= 7;
  }
  printf("%s\n", names[ans].c_str());
  return 0;
}
