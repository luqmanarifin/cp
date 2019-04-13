#include <bits/stdc++.h>

using namespace std;

const int N = 18;
vector<int> strategy = {16, 11, 13, 17, 15, 9};
int ret[N];

map<vector<int>, int> mp;

int main() {
  // set<vector<int> > lol;
  // for (int i = 1; i <= 1000000; i++) {
  //   vector<int> num;
  //   for (auto it : strategy) {
  //     num.push_back(i % it);
  //   }
  //   if (lol.count(num)) {
  //     printf("double %d with %d\n", i, mp[num]);
  //     return 0;
  //   }
  //   mp[num] = i;
  //   lol.insert(num);
  // }
  // puts("perfectly unique");
  // return 0;

  int t, n, m;
  scanf("%d %d %d", &t, &n, &m);
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < strategy.size(); j++) {
      int it = strategy[j];
      for (int i = 0; i < N; i++) {
        printf("%d", it);
        printf("%c", i + 1 == N? '\n' : ' ');
      }
      fflush(stdout);
      int sum = 0;
      for (int i = 0; i < N; i++) {
        int v;
        scanf("%d", &v);
        sum += v;
      }
      sum %= it;
      ret[j] = sum;
    }
    int ans = -1;
    for (int i = 1; i <= m; i++) {
      bool nice = 1;
      for (int j = 0; j < strategy.size(); j++) {
        if (i % strategy[j] != ret[j]) {
          nice = 0;
        }
      }
      if (nice) {
        ans = i;
        break;
      }
    }
    assert(ans != -1);
    printf("%d\n", ans);
    fflush(stdout);
    int v;
    scanf("%d", &v);
    assert(v == 1);
  }

  return 0;
}
