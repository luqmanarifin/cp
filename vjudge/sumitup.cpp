#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[200], sum, n;
bool ada;
map<string, bool> mp;

void rek(int now, int pos, string str) {
  if (now > sum) return;
  if (sum == now) {
    ada = 1;
    if (!mp[str]) {
      cout << str.substr(1, str.size() - 1) << '\n';
    }
    mp[str] = 1;
    return;
  }
  if (pos == n) return;
  for (int i = pos; i < n; i++) {
    rek(now + a[i], i + 1, str + "+" + to_string(a[i]));
  }
}

int main() {
  while (cin >> sum >> n) {
    if (sum == 0 || n == 0) return 0;
    mp.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    reverse(a, a + n);
    printf("Sums of %d:\n", sum);
    ada = 0;
    rek(0, 0, "");
    if (!ada) puts("NONE");
  }

  return 0;
}
