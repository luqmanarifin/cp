#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int OFFSET = (1 << 17);
const int OFFSET2 = (1 << 18);

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  vector<int> ans;
  if (n == 1) {
    ans.push_back(x);
  } else if ((n - 1) % 4 == 0) {
    ans.push_back(x);

    int kali = (n - 1) / 4, it = 0;
    for (int i = 0; it < kali; i++) {
      int num1 = i * 2;
      int num2 = i * 2 + 1;
      if (num1 == x || num2 == x) continue;
      it++;
      ans.push_back(num1);
      ans.push_back(num2);
      ans.push_back(num1 | OFFSET);
      ans.push_back(num2 | OFFSET);
    }
  } else if ((n - 1) % 4 == 1) {
    if (n == 2 && x == 0) {
      puts("NO");
      return 0;
    }
    if (x == 0) {

      ans.push_back(0);
      int kali = (n - 1) / 4, it = 0;
      for (int i = 0; it < kali; i++) {
        int num1 = i * 2;
        int num2 = i * 2 + 1;
        if (num1 == 0 || num2 == 0) continue;
        it++;
        ans.push_back(num1);
        ans.push_back(num2);
        ans.push_back(num1 | OFFSET);
        ans.push_back(num2 | OFFSET);
      }
      ans.back() |= OFFSET2;
      ans.push_back(OFFSET2);

    } else {
      ans.push_back(x);
      ans.push_back(0);
      int kali = (n - 1) / 4, it = 0;
      for (int i = 0; it < kali; i++) {
        int num1 = i * 2;
        int num2 = i * 2 + 1;
        if (num1 == x || num2 == x) continue;
        if (num1 == 0 || num2 == 0) continue;
        it++;
        ans.push_back(num1);
        ans.push_back(num2);
        ans.push_back(num1 | OFFSET);
        ans.push_back(num2 | OFFSET);
      }
    }

  } else if ((n - 1) % 4 == 2) {
    ans.push_back(x);

    int kali = (n - 1) / 4, it = 0;
    for (int i = 0; it < kali; i++) {
      int num1 = i * 2;
      int num2 = i * 2 + 1;
      if (num1 == x || num2 == x) continue;
      it++;
      ans.push_back(num1);
      ans.push_back(num2);
      ans.push_back(num1 | OFFSET);
      ans.push_back(num2 | OFFSET);
    }
    ans.back() |= OFFSET;
    ans.push_back(OFFSET2);
    ans.push_back(OFFSET | OFFSET2);
  } else if ((n - 1) % 4 == 3) {
    ans.push_back(x);

    int kali = (n - 1) / 4, it = 0;
    for (int i = 0; it < kali; i++) {
      int num1 = i * 2;
      int num2 = i * 2 + 1;
      if (num1 == x || num2 == x) continue;
      it++;
      ans.push_back(num1);
      ans.push_back(num2);
      ans.push_back(num1 | OFFSET);
      ans.push_back(num2 | OFFSET);
    }
    ans.push_back(OFFSET - 1);
    ans.push_back(OFFSET2);
    ans.push_back((OFFSET - 1) | OFFSET2);
  }
  puts("YES");
  random_shuffle(ans.begin(), ans.end());
  for (auto it : ans) printf("%d ", it);
  return 0;
}
