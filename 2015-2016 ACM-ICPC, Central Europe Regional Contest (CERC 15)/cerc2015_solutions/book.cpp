// Author: Luka Kalinovcic
#include <cstdio>
#include <cstring>

#define MAX 500000

int n;
char s[MAX + 1];
int start[MAX];
int word_len[MAX];

int Start(int i) {
  return i < n ? start[i] : n;
}

int Solve(int L) {
  int ret = 0;
  for (int pos = 0; pos < n; pos = Start(pos + L)) {
    ret += word_len[pos] + 1;
  }
  return ret - 1;
}

int main() {
  gets(s);
  n = strlen(s);
  s[n] = ' ';
  int word_start = 0;
  for (int i = 0; i <= n; ++i) {
    if (s[i] == ' ') {
      word_len[word_start] = i - word_start;
      word_start = i + 1;
    }
    start[i] = word_start;
  }

  int A, B;
  scanf("%d%d", &A, &B);
  for (int q = A; q <= B; ++q) {
    printf("%d\n", Solve(q));
  }

  return 0;
}
