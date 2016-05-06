#include <bits/stdc++.h>

using namespace std;

string n, k;
int cnt[10];

void push(int digit, int add) {
  while(digit > 0) {
    cnt[digit % 10] += add;
    digit /= 10;
  }
}

void k_modify(int add) {
  for(int i = 0; i < k.length(); i++) {
    cnt[k[i] - '0'] += add;
  }
}

int digit(int c) {
  int ret = 0;
  while(c > 0) {
    ret++;
    c /= 10;
  }
  return ret;
}

// len is between 1 .. 1 juta
bool can(int len) {
  int c = n.length() - len;
  if(digit(len) != c) return 0;
  push(len, -1);
  bool ret = 1;
  for(int i = 0; i < 10; i++) {
    if(cnt[i] < 0) ret = 0;
  }
  push(len, 1);
  return ret;
}

string sisip(string str, int at) {
  string ret;
  for(int i = 0; i <= str.size(); i++) {
    if(i == at) ret = ret + k;
    if(i < str.size()) ret.push_back(str[i]);
  }
  return ret;
}

int main() {
  cin >> n >> k;
  string ans = n;
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for(int i = 0; i < n.length(); i++) {
    cnt[n[i] - '0']++;
  }
  
  for(int len = 1; len <= min(7, (int)n.size() - 1); len++) {
    if(can(n.length() - len)) {
      push(n.length() - len, -1);
      k_modify(-1);
      
      string rem = "";
      bool allZero = 1;
      for(int i = 0; i < 10; i++) {
        for(int j = 0; j < cnt[i]; j++) {
          if(i) allZero = 0;
          rem.push_back(i + '0');
        }
      }
      if(rem[0] == '0' && !allZero) {
        int p = -1;
        for(int i = 0; i < rem.size(); i++) if(rem[i] != '0' && p == -1) p = i;
        string tmp = ""; tmp.push_back(rem[p]);
        for(int i = 0; i < rem.size(); i++) if(i != p) tmp.push_back(rem[i]);
        rem = tmp;
      }
      string cur;
      if(allZero) {
        cur = k + rem;
      } else {
        bool low = 1;
        for(int i = 1; i < k.length(); i++) if(k[i - 1] < k[i]) {
          low = 0;
          break;
        }
        int at = -1;
        if(low) {
          at = lower_bound(rem.begin() + 1, rem.end(), k[0]) - rem.begin();
        } else {
          at = upper_bound(rem.begin() + 1, rem.end(), k[0]) - rem.begin();
        }
        at = min(at, (int) rem.size());
        
        // sisip ke depan
        if(k[0] < rem[0] && k[0] != '0') {
          sort(rem.begin(), rem.end());
          cur = k + rem;
        } else {
          cur = sisip(rem, at);
        }
      }
      ans = min(ans, cur);
      //cout << len << endl;
      
      k_modify(1);
      push(n.length() - len, 1);
    }
  }
  cout << ans << endl;
  return 0;
}