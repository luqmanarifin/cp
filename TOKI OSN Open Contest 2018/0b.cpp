#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char junk[20];
int cnt[N];
bool aku[15], dia[15], both[15];
deque<int> urut;

bool can() {
  for (int i = 1; i <= 10; i++) {
    if (cnt[i] && (aku[i] || dia[i])) {
      return 1;
    }
  }
  return 0;
}

int answer() {
  while (!urut.empty() && cnt[urut.front()] == 0) {
    urut.pop_front();
  }
  int ans = 0;
  if (urut.empty()) {
    printf("%d\n", 0);
  } else {
    ans = urut.front();
    printf("%d\n", urut.front());
    cnt[urut.front()]--;
  }
  fflush(stdout);
  return ans;
}

int read() {
  int v;
  scanf("%d", &v);
  cnt[v]--;
  return v;
}

int main() {
  scanf("%s", junk);
  int n, s;
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%d", cnt + i);
  }
  int x;
  scanf("%d", &x);
  while (x--) {
    int v;
    scanf("%d", &v);
    aku[v] = 1;
  }

  scanf("%d", &x);
  while (x--) {
    int v;
    scanf("%d", &v);
    dia[v] = 1;
  }

  for (int i = 1; i <= 10; i++) {
    if (aku[i] && dia[i]) {
      both[i] = 1;
    }
  }

  for (int i = 1; i <= 10; i++) {
    if (both[i]) {
      urut.push_back(i);
    }
  }
  for (int i = 1; i <= 10; i++) {
    if (aku[i] && !both[i]) {
      urut.push_back(i);
    }
  }
  int bef = -1;
  while (1) {
    if (bef == 0 && !can()) {
      printf("0\n");
      fflush(stdout);
      break;
    }
    bef = answer();
    int now = read();
    if (now == bef && now == 0) {
      break;
    }
  }

  return 0;
}
