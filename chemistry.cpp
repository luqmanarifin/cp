#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n;
string s[N];

string dig(int k) {
  string ret = "";
  bool ok = 0;
  for(int i = 30; i >= 0; i--) {
    if(k & (1 << i)) ok = 1;
    if(ok) {
      if(k & (1 << i)) ret.push_back('1');
      else ret.push_back('0');
    }
  }
  return ret;
}

int get(string t) {
  int ret = 0;
  for(int i = 0; i < n; i++) {
    int same = 0;
    for(int j = 0; j < s[i].length() && j < t.length(); j++) {
      if(s[i][j] == t[j]) {
        same++;
      } else {
        break;
      }
    }
    ret += s[i].length() - same + t.length() - same;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    s[i] = dig(a[i]);
    //cout << s[i] << endl;
  }
  string pre = s[0];
  for(int i = 1; i < n; i++) {
    int same = 0;
    for(int j = 0; j < pre.length() && j < s[i].length(); j++) {
      if(pre[j] == s[i][j]) {
        same++;
      } else {
        break;
      }
    }
    int dif = pre.length() - same;
    while(dif--) pre.pop_back();
  }
  //cout << pre << endl;
  int ans = get(pre);
  while(pre.length() <= 30) {
    ans = min(ans, get(pre));
    pre.push_back('0');
  }
  cout << ans << endl;
  return 0;
}
