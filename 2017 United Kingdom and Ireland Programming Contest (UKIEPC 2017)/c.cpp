#include <bits/stdc++.h>

using namespace std;

string s[] = {"red", "yellow", "green", "brown", "blue", "pink", "black"};

string a[25];

int main() {
  int n;
  cin >> n;
  int red = 0;
  int best = -1, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == "red") {
      red++;
    } else {
      for (int j = 1; j < 7; j++) {
        if (s[j] == a[i]) {
          if (j + 1 > best) {
            best = j + 1;
          }
          sum += j + 1;
        }
      }
    }
  }
  if (best == -1) {
    cout << 1 << endl;
  } else {
    int ans = red * (1 + best) + sum;
    cout << ans << endl;
  }

  return 0;
}
