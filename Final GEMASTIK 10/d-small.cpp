#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int BIG = 2e7;
const int mod = 1e9 + 7;

int power(long long a, long long b) {
  long long tmp = 1;
  for (int i = 0; i < b; i++) tmp *= a;
  return tmp;
}

int st[N];
vector<int> dp[10];
int pw[10];

int encode(int len) {
  int ret = 0;
  for (int i = 0; i < len; i++) ret = ret * 26 + st[i];
  return ret;
}

void decode(int now, int len) {
  for (int i = len - 1; i >= 0; i--) {
    st[i] = now % 26;
    now /= 26;
  }
}

int dfs(int len, int now) {
  if (dp[len][now] != -1) return dp[len][now];
  //printf("%d %d\n", len, now);
  set<int> ada;
  for (int i = 0; i < len; i++) {
    int ori = st[i];
    now -= st[i] * pw[len - 1 - i];
    for (int j = st[i] + 1; j < 26; j++) {
      if (i + 1 < len && j > st[i + 1]) break;
      st[i] = j;
      ada.insert(dfs(len, now + j * pw[len - 1 - i]));
    }
    st[i] = ori;
    now += st[i] * pw[len - 1 - i];
  }
  for (int i = 0; ; i++) if (!ada.count(i)) return dp[len][now] = i;
}

int cnt[10][200], valid[20];
char s[10];

bool ok(int len) {
  for (int i = 0; i + 1 < len; i++) if (st[i] > st[i + 1]) return 0;
  return 1;
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < 10; i++) pw[i] = pw[i - 1] * 26;

  for (int len = 1; len <= 5; len++) {
    int to = power(26, len);
    dp[len].assign(to, -1);
    //printf("%d: %d\n", len, to);
    for (int j = 0; j < to; j++) {
      decode(j, len);
      if (!ok(len)) continue;
      valid[len]++;
      //printf("BIG %d\n", j);
      cnt[len][dfs(len, j)]++;
      /*
      if (len == 2) {
        for (int k = 0; k < len; k++) {
          printf("%d ", st[k]);
        }
        printf(": %d\n", dfs(len, j));

      }
      */
    }
    /*
    if (len == 2) {
      for (int k = 0; k < 200; k++) printf("%d ada %d\n", k, cnt[len][k]);
    }
    */
    //puts("JANCOK");
  }
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < 200; j++) {
      cnt[i][j] += cnt[i - 1][j];
      cnt[i][j] %= mod;
    }
  }
  //puts("done");
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, l;
    scanf("%d %d %s", &n, &l, s);
    assert(n == 2);
    int len = strlen(s);
    for (int i = 0; i < len; i++) st[i] = s[i] - 'a';
    int nim = dp[len][encode(len)];
    //printf("nim %d\n", nim);
    long long ans = 0;
    for (int i = 1; i <= l; i++) ans += valid[i];
    ans -= cnt[l][nim];
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }

  return 0;
}