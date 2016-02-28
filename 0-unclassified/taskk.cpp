#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int magic = 320;

char s[N];

int at[N];
int cnt[magic][26], n;
int size;

// 0 is relax, 1 is gak nyante
int relax[magic];

// berlaku kalo relax = 1
// 0 = desc, 1 = asc
int asc[magic];

void push(int p) {
  if(relax[p]) {
    if(asc[p]) {
      int j = 0, c = 0;
      for(int i = p * size; i < n && i < (p + 1) * size; i++) {
        while(cnt[p][j] == 0) j++;
        s[i] = j + 'a';
        c++;
        if(c == cnt[p][j]) {
          c = 0;
          j++;
        }
      }
    } else {
      int j = 25, c = 0;
      for(int i = p * size; i < n && i < (p + 1) * size; i++) {
        while(cnt[p][j] == 0) j--;
        s[i] = j + 'a';
        c++;
        if(c == cnt[p][j]) {
          c = 0;
          j--;
        }
      }
    }
    relax[p] = 0;
  }
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  size = (int) (sqrt(n) + 0.5);
  for(int i = 0; i * size < n; i++) {
    for(int j = 0; j < size && i * size + j < n; j++) {
      at[i * size + j] = i;
      cnt[i][s[i * size + j] - 'a']++;
    }
  }
  
  int tmp[26];
  while(q--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    l--; r--;
    memset(tmp, 0, sizeof(tmp));
    push(at[l]); push(at[r]);
    
    if(at[l] == at[r]) {
      sort(s + l, s + r + 1);
      if(k == 0) {
        reverse(s + l, s + r + 1);
      }
      continue;
    }
    
    for(int i = l; i < (at[l] + 1) * size && i < n; i++) {
      tmp[s[i] - 'a']++;
      cnt[at[l]][s[i] - 'a']--;
    }
    for(int i = at[l] + 1; i < at[r]; i++) {
      for(int j = 0; j < 26; j++) {
        tmp[j] += cnt[i][j];
        cnt[i][j] = 0;
      }
      relax[i] = 1;
      asc[i] = k;
    }
    for(int i = at[r] * size; i <= r; i++) {
      tmp[s[i] - 'a']++;
      cnt[at[r]][s[i] - 'a']--;
    }
    
    if(k == 1) {
      int j = 0;
      for(int i = l; i < (at[l] + 1) * size && i < n; i++) {
        while(tmp[j] == 0) j++;
        s[i] = j + 'a';
        cnt[at[l]][j]++;
        tmp[j]--;
      }
      for(int i = at[l] + 1; i < at[r]; i++) {
        int rem = size;
        while(rem) {
          while(tmp[j] == 0) j++;
          int del = min(tmp[j], rem);
          cnt[i][j] = del;
          rem -= del;
          tmp[j] -= del;
        }
      }
      for(int i = at[r] * size; i <= r; i++) {
        while(tmp[j] == 0) j++;
        s[i] = j + 'a';
        cnt[at[r]][j]++;
        tmp[j]--;
      }
    } else {
    
      int j = 25;
      for(int i = l; i < (at[l] + 1) * size && i < n; i++) {
        while(tmp[j] == 0) j--;
        s[i] = j + 'a';
        cnt[at[l]][j]++;
        tmp[j]--;
      }
      for(int i = at[l] + 1; i < at[r]; i++) {
        int rem = size;
        while(rem) {
          while(tmp[j] == 0) j--;
          int del = min(tmp[j], rem);
          cnt[i][j] = del;
          rem -= del;
          tmp[j] -= del;
        }
      }
      for(int i = at[r] * size; i <= r; i++) {
        while(tmp[j] == 0) j--;
        s[i] = j + 'a';
        cnt[at[r]][j]++;
        tmp[j]--;
      }
    }
  }
  for(int i = 0; i * size < n; i++) push(i);
  printf("%s\n", s);
  return 0;
}
