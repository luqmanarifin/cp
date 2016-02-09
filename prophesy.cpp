#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> ada;
char s[N];
const int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char good[] = "00-00-0000";
int ret[10];

int valid(int d, int m, int y) {
  if(!(2013 <= y & y <= 2015)) {
    return 0;
  }
  if(!(1 <= m && m <= 12)) {
    return 0;
  }
  if(!(1 <= d && d <= day[m - 1])) {
    return 0;
  }
  return 1;
}

int id(int d, int m, int y) {
  return y + m * 10000 + d * 1000000;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i + 10 <= n; i++) {
    bool nice = 1;
    for(int j = 0; j < 10; j++) {
      if(good[j] == '-') {
        if(s[i + j] != '-') {
          nice = 0;
          break;
        }
      } else {
        if(s[i + j] == '-') {
          nice = 0;
          break;
        }
        ret[j] = s[i + j] - '0';
      }
    }
    if(nice) {
      //printf("%d nice\n", i);
      int d = ret[0] * 10 + ret[1];
      int m = ret[3] * 10 + ret[4];
      int y = ret[6] * 1000 + ret[7] * 100 + ret[8] * 10 + ret[9];
      //printf("%d %d %d\n", d, m, y);
      if(valid(d, m, y)) {
        ada.push_back(id(d, m, y));
      }
    }
  }
  sort(ada.begin(), ada.end());
  int cnt = 0;
  for(int i = 0; i < ada.size(); i++) {
    int j = i;
    while(j + 1 < ada.size() && ada[j + 1] == ada[j]) {
      j++;
    }
    cnt = max(cnt, j - i + 1);
    i = j;
  }
  for(int i = 0; i < ada.size(); i++) {
    int j = i;
    while(j + 1 < ada.size() && ada[j + 1] == ada[j]) {
      j++;
    }
    if(j - i + 1 == cnt) {
      int d = ada[i] / 1000000;
      int m = ada[i] / 10000 % 100;
      int y = ada[i] % 10000;
      printf("%d%d-%d%d-%d", d/10, d%10, m/10, m%10, y);
      return 0;
    }
    i = j;
  }
  return 0;
}
