#include <bits/stdc++.h>

using namespace std;

int ask(vector<int> a) {
  printf("?");
  for (auto it : a) printf(" %d", it);
  printf("\n");
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}

void answer(vector<int> a) {
  printf("!");
  for (auto it : a) printf(" %d", it);
  printf("\n");
  fflush(stdout);
}

int main() {
  srand(time(0));

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> now, a;
    for (int i = 1; i <= n; i++) a.push_back(i);
    random_shuffle(a.begin(), a.end());
    now = {a[0], a[1], a[2]};
    int ans = ask(now);
    while (ans != 0) {
      random_shuffle(now.begin(), now.end());
      now = {ans, now[0], now[1]};
      ans = ask(now);
    }
    answer(now);
  }

  return 0;
}
