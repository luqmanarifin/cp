#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[105][2];
bool done[N];
int a[105];

int main() {
  int q;
  scanf("%d", &q);
  set<int> now;
  for(int i = 0; i < q; i++) {
    scanf("%s %d", s[i], a + i);
    if(!done[a[i]] && s[i][0] == '-') {
      now.insert(a[i]);
    }
    done[a[i]] = 1;
  }
  int ans = now.size();
  for(int i = 0; i < q; i++) {
    if(s[i][0] == '+') {
      now.insert(a[i]);
    } else {
      now.erase(a[i]);
    }
    ans = max(ans, (int) now.size());
  }
  cout << ans << endl;
  return 0;
}
