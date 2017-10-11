#include <bits/stdc++.h>

using namespace std;

int ask(int now) {
  printf("%d\n", now);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}
int main() {
  srand(time(0));
  int t;
  scanf("%d", &t);
  while (t--) {
    int wow = rand() % 100;
    int a = ask(wow);
    int b = ask((wow + 10) % 100);
    if (a == 0 && b == 0) {
      int v = -1;
      vector<int> num;
      for (int i = 1; i < 10; i++) num.push_back((wow + i) % 100);
      int kali = 10;
      while (kali--) random_shuffle(num.begin(), num.end());
      for (int i = 0; i < 8; i++) {
        int k = ask(num[i]);
        if (k == 1) {
          v = num[i];
        }
      }
      ask((v + 10) % 100);
    } else if (a == 0 && b) {
      int done = 2;
      for (int i = 1; i < 10; i++) {
        int k = ask((wow + i) % 100);
        done++;
        if (k == 1) break;
      }
      int now = wow;
      while (done < 11) {
        now = (now + 90) % 100;
        ask(now);
        done++;
      }
    } else if (a && b == 0) {
      int done = 2;
      for (int i = 9; i > 0; i--) {
        int k = ask((wow + i) % 100);
        done++;
        if (k == 1) break;
      }
      int now = (wow + 10) % 100;
      while (done < 11) {
        now = (now + 10) % 100;
        ask(now);
        done++;
      }
    } else {
      vector<int> num;
      for (int i = 1; i < 100; i += 10) {
        num.push_back((wow + i) % 100);
      }
      int kali = 10;
      while (kali--) random_shuffle(num.begin(), num.end());
      int p = rand() % num.size();
      int start = num[p];
      for (int i = 0; i < 9; i++) {
        ask((start + i) % 100);
      }
    }
  }
  return 0;
}
