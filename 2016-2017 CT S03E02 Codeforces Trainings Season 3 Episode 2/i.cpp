#include <bits/stdc++.h>

using namespace std;

const int N = 25e3 + 5;

int s[N];
bool done[10];

int main() {
  srand(time(0));
  for (int i = 1; i < N; i++) {
    memset(done, 0, sizeof(done));
    for (int j = 0; j <= i - 1 - j; j++) {
      if (s[j] == s[i - 1 - j]) {
        done[s[j]] = 1;
      }
    }
    bool ada = 0;
    vector<int> wow;
    for (int j = 0; j < 10; j++) {
      if (!done[j]) {
        ada = 1;
        wow.push_back(j);
      }
    }
    if (!ada) {
      printf("isi %d gak bisa\n", i + 1);
      return 0;
    }
    int at = rand() % wow.size();
    s[i] = (i % 79 >= 30? wow[0] : wow.back());
    printf("%d", s[i]);
  }
  return 0;
}
