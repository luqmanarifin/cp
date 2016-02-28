#include <bits/stdc++.h>

using namespace std;

void add(string& s) {
  for(int i = 0; i < s.length(); i++) {
    if(s[i] != '9') {
      s[i]++;
      return;
    }
    s[i] = '0';
  }
  s.push_back('1');
}

void get(string& s, int k) {
  int low = 0, hig = 0;
  for(int i = 0; i < s.length(); i++) {
    low += s[i] - '0';
    hig += s[i] - '0';
  }
  for(int i = 0; i < s.length(); i++) {
    hig += 9 - (s[i] - '0');
    if('0' <= s[i] && s[i] <= '9') {
      //printf("%d %d %s\n", low, hig, s.c_str());
      if(low <= k && k <= hig) {
        int rem = k - low;
        for(int j = 0; rem; j++) {
          int can = '9' - s[j];
          int add = min(can, rem);
          rem -= add;
          s[j] += add;
        }
        return;
      }
    }
    low += 1 - (s[i] - '0');
    hig++;
    s[i] = '0';
    if(i + 1 < s.length()) {
      s[i + 1]++;
    } else {
      s.push_back('1');
    }
  }
}

int main() {
  string now = "1";
  int n;
  scanf("%d", &n);
  while(n--) {
    int k;
    scanf("%d", &k);
    get(now, k);
    reverse(now.begin(), now.end());
    printf("%s\n", now.c_str());
    reverse(now.begin(), now.end());
    add(now);
  }
  
  return 0;
}
