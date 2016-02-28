#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N];
vector<int> pos;
int n;

long long cnt(int l, int r) {
  if(l > r) {
    return 0;
  }
  long long ret = 0;
  for(int i = l; i <= r && i < n; ) {
    long long now = s[i] - '0';
    int j = i + 1;
    while(s[j] == '*' && j < r && j < n) {
      now *= s[j + 1] - '0';
      j += 2;
    }
    ret += now;
    i = j + 1;
  }
  return ret;
}

long long cnt_bracket(int l, int r) {
  long long ret = 0;
  for(int i = 0; i < n; ) {
    long long now;
    if(l <= i && i <= r) {
      now = cnt(l, r);
      i = r;
    } else {
      now = s[i] - '0';
    }
    int j = i + 1;
    while((s[j] == '*' && j < n) || (j == l - 1)) {
      if(j == l - 1) {
        now *= cnt(l, r);
        j = r + 1;
      } else {
        now *= s[j + 1] - '0';
        j += 2;
      }
    }
    ret += now;
    i = j + 1;
  }
  return ret;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  
  pos.push_back(-1);
  for(int i = 0; i < n; i++) {
    if(s[i] == '*') {
      pos.push_back(i);
    }
  }
  pos.push_back(n);
  
  
  long long ans = cnt(0, n - 1);
  for(int i = 0; i < pos.size(); i++) {
    for(int j = i + 1; j < pos.size(); j++) {
      ans = max(ans, cnt_bracket(pos[i] + 1, pos[j] - 1));
    }
  }
  cout << ans << endl;
  return 0;
}
