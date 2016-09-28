#include <bits/stdc++.h>

using namespace std;

const int N = 25e3 + 5;

int s[N];
bool done[10];
int cnt[10];

int main() {
  srand(time(0));
  for (int i = 1; i < N; i++) {
    memset(done, 0, sizeof(done));
    for (int j = 0; j <= i - 1 - j; j++) {
      if (s[j] == s[i - 1 - j]) {
        done[s[j]] = 1;
      }
    }
    vector<int> wow;
    for (int j = 0; j < 10; j++) {
      if (done[j] == 0) {
        wow.push_back(j);
      }
    }
    if (wow.empty()) {
      printf("\ngagal at %d\n", i + 1);
      return 0;
    }
    memset(cnt, 0, sizeof(cnt));
    for (int j = 0; j < i; j++) {
      cnt[s[j]]++;
    }
    int p = -1, best = 1e9;
    for (auto it : wow) {
      if (cnt[it] < best) {
        best = cnt[it];
        p = it;
      }
    }
    int at = rand() % wow.size();
    s[i] = (i % 2048 < 1023? wow[0] : wow.back());
    printf("%d", s[i]);
  }
  return 0;
}
