#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e9;

int ans[N];

template <class T>
inline std::string to_string (const T& t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}

long long balik(long long a) {
  string rev = to_string(a);
  reverse(rev.begin(), rev.end());
  long long ret = atoi(rev.c_str());
  return ret;
}

int main() {
  for(int i = 0; i < N; i++) {
    ans[i] = inf;
  }
  ans[0] = 0;
  for(int i = 0; i < N - 1; i++){
    ans[i + 1] = min(ans[i + 1], ans[i] + 1);
    int rev = (int) balik(i);
    if(i < rev && rev < N) {
      ans[rev] = min(ans[rev], ans[i] + 1);
    }
  }

  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: %d\n", tt, ans[n]);
  }
  
  return 0;
}
