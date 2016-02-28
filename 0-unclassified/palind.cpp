#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int cnt[26];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  int i = 0, j = 25;
  while(i < j) {
    while(i < 26 && cnt[i] % 2 == 0) i++;
    while(j >= 0 && cnt[j] % 2 == 0) j--;
    if(i < 26 && j >= 0 && i <= j) {
      cnt[i]++;
      cnt[j]--;
    }
    i++; j--;
  }
  int mid = -1;
  for(int i = 0; i < 26; i++) {
    if(cnt[i] % 2) {
      mid = i;
      cnt[i]--;
    }
    cnt[i] /= 2;
  }
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < cnt[i]; j++) {
      printf("%c", i + 'a');
    }
  }
  if(mid != -1) printf("%c", mid + 'a');
  for(int i = 25; i >= 0; i--) {
    for(int j = 0; j < cnt[i]; j++) {
      printf("%c", i + 'a');
    }
  }
  return 0;
}
