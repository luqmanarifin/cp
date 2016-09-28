#include <bits/stdc++.h>

using namespace std;

map<int, int> cnt;
map<int, int> bin[32];

void insert(int v) {
  int now = 0;
  for (int i = 30; i >= 0; i--) {
    int mask = (1 << i);
    if (v & mask) {
      now += mask;
    }
    bin[i][now]++;
  }
}

void erase(int v) {
  if(v == 0 && cnt[v] == 1) return;
  int now = 0;
  for (int i = 30; i >= 0; i--) {
    int mask = (1 << i);
    if (v & mask) {
      now += mask;
    }
    bin[i][now]--;
  }
}

int find(int v) {
  int now = 0;
  for (int i = 30; i >= 0; i--) {
    int mask = (1 << i), good, bad;
    if (v & mask) {
      good = now;
      bad = now + mask;
    } else {
      good = now + mask;
      bad = now;
    }
    if (bin[i][good]) {
      now = good;
    } else {
      assert(bin[i][bad]);
      now = bad;
    }
  }
  return now ^ v;
}

int main() {
  int q;
  scanf("%d", &q);
  insert(0);
  while (q--) {
    char c;
    int v;
    scanf(" %c %d", &c, &v);
    if (c == '+') {
      insert(v);
    } else if (c == '-') {
      erase(v);
    } else {
      printf("%d\n", find(v));
    }
  }
  return 0;
}
