#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int aft[N];
int bef[N];
bool ada[N];

char s[100];
string ret;

int main() {
  srand(1234);
  int n, k;
  scanf("%s %d %d", s, &n, &k);
  if(s[1] == '1') {
    for(int i = 0; i < 3; i++) {
      ada[i + 1] = 1;
    }
    //printf("JAWAB BBBCAAAAAA\n");
    //fflush(stdout);
    //return 0;
  } else if(s[3] == '3') {
    for(int i = 0; i < 26; i++) {
      ada[i + 1] = 1;
    }
  } else {
    for(int i = 0; i < 26; i++) {
      printf("TANYA %c\n", i + 'A');
      fflush(stdout);
      cin >> ret;
      if(ret == "YA") {
        ada[i + 1] = 1;
      }
    }
  }
  int word = 0;
  for(int i = 1; i <= 26; i++) {
    if(ada[i]) word++;
  }
  
  bool maju = 1;
  int now = rand() % 26 + 1;
  while(!ada[now]) now = rand() % 26 + 1;
  
  int start = now;
  while(true) {
    ada[now] = 0;
    vector<int> temp;
    for(int i = 1; i <= 26; i++) {
      if(ada[i]) {
        temp.push_back(i);
      }
    }
    if(temp.empty()) {
      break;
    }
    int kali = rand() % 30;
    while(kali--) random_shuffle(temp.begin(), temp.end());
    int found = 0;
    for(auto it : temp) {
      if(maju) {
        printf("TANYA %c%c\n", now - 1 + 'A', it - 1 + 'A');
      } else {
        printf("TANYA %c%c\n", it - 1 + 'A', now - 1 + 'A');
      }
      fflush(stdout);
      cin >> ret;
      if(ret == "YA") {
        found = it;
        break;
      }
    }
    if(found) {
      if(maju) {
        aft[now] = found;
        bef[found] = now;
        now = found;
      } else {
        start = found;
        aft[found] = now;
        bef[now] = found;
        now = found;
      }
    } else {
      if(maju) {
        maju ^= 1;
        while(bef[now]) now = bef[now];
      } else {
        break;
      }
    }
  }
  vector<char> ans;
  while(start) {
    word--;
    if(word == 0) {
      for(int i = 0; i < n; i++) {
        ans.push_back(start - 1 + 'A');
      }
      break;
    }
    int l = 1, r = n - word;
    while(l < r) {
      int mid = (l + r + 1) >> 1;
      printf("TANYA ");
      for(int i = 0; i < mid; i++) {
        printf("%c", start - 1 + 'A');
      }
      printf("\n");
      fflush(stdout);
      cin >> ret;
      if(ret == "YA") l = mid;
      else r = mid - 1;
    }
    for(int i = 0; i < l; i++) {
      ans.push_back(start - 1 + 'A');
    }
    n -= l;
    start = aft[start];
  }
  printf("JAWAB ");
  for(auto it : ans) {
    printf("%c", it);
  }
  printf("\n");
  fflush(stdout);
  
  return 0;
}
