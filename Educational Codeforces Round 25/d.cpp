#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N], t[N];
int cnt[30], need[30];
int ask;

bool can(int kali) {
  long long butuh = 0;
  for (int i = 0; i < 26; i++) {
    if (need[i] * kali > cnt[i]) {
      butuh += need[i] * kali - cnt[i];
    }
  }
  return butuh <= ask;
}

void solve(int kali) {
  int p = 0;
  for (int i = 0; i < 26; i++) {
    //printf("butuh %d, ada %d\n", need[i] * kali, cnt[i]);
    if (need[i] * kali > cnt[i]) {
      int isi = need[i] * kali - cnt[i];
      int now = 0;
      //printf("need %c\n", i + 'a');
      for (; now < isi; p++) {
        if (s[p] == '?') {
          s[p] = i + 'a';
          now++;
        }
      }
    }
  }
  //printf("p %d\n", p);
  int len = strlen(s);
  for (; p < len; p++) {
    if (s[p] == '?') {
      s[p] = 'a';
    }
  }
}

int main() {
  scanf("%s %s", s, t);
  int slen = strlen(s);
  int tlen = strlen(t);
  for (int i = 0; i < slen; i++) {
    if (s[i] == '?') {
      ask++;
    } else {
      cnt[s[i] - 'a']++;
    }
  }
  for (int i = 0; i < tlen; i++) {
    need[t[i] - 'a']++;
  }
  int l = 0, r = slen / tlen;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  //printf("%d\n", l);
  solve(l);
  printf("%s\n", s);
  return 0;
}
