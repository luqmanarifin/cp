#include <bits/stdc++.h>

using namespace std;

const int N = 10000;


vector<int> vp;
bool isprime[N];
int grund[N];

int main() {
  fill(isprime, isprime+N, 1);
  for (int i = 2; i < N; ++i) {
    if (!isprime[i]) continue;
    vp.push_back(i-1);
    for (int j = i+i; j < N; j += i)
      isprime[j] = 0;
  }
  grund[0] = 0;
  for (int i = 0; i < N; ++i) {
    grund[i] = 0;
    set<int> st;
    for (int p : vp) {
      if (p > i) break;
      st.insert(grund[i-p]);
    }
    for (int x : st) {
      if (x != grund[i])
        break;
      ++grund[i];
    }
    if (grund[i] == 0)
    printf("%d %d\n", i, grund[i]);
  }


  return 0;
}