/*

Our shadows stretch out on the pavement
As I walk in the twilight with you
If we could be together like this forever
Holding hands
It's almost enough to make me cry

The wind grows colder
I can smell winter
Soon the season will come to this town
When I can get close to you

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just love you
I thought so with all my heart

I feel like when I'm with you
I can overcome anything
I pray that these days
Will continue forever

The wind rattled the window
The night shakes you awake
I will change any sorrow
Into a smile

The snow flowers fell
Outside the window
Unceasing
And colored our town
I realized that love means
Wanting to do something
For someone else

If I should lose you
I'll become a star and shine on you
I'll be with you even on nights
When your smile is wet with tears

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just want to be like this
With you forever
I can honestly think that now

The pure white snow flowers
Bury this town
Softly drawing memories in our hearts
Together forever with you...

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

char s[N][N];
int n, m;
int cnt[N][N];
int dp[N][N][4];

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

int find(int i, int j, int p, int q) {
  if (i > p || j > q) {
    swap(i, p);
    swap(j, q);
  }
  return cnt[p][q] - cnt[i-1][q] - cnt[p][j-1] + cnt[i-1][j-1];
}

int main() {
  int K;
  scanf("%d %d %d", &n, &m, &K);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  int s1, s2, f1, f2;
  scanf("%d %d %d %d", &s1, &s2, &f1, &f2);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt[i][j] = (s[i][j] == '#');
      cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
      for (int k = 0; k < 4; k++) dp[i][j][k] = inf;
    }
  }
  queue<tuple<int, int, int>> q;
  for (int k = 0; k < 4; k++) {
    dp[s1][s2][k] = 0;
    q.emplace(s1, s2, k);
  }
  while (!q.empty()) {
    int ni, nj, nk;
    tie(ni, nj, nk) = q.front();
    //printf("%d %d %d: %d\n", ni, nj, nk, dp[ni][nj][nk]);
    q.pop();
    if (ni == f1 && nj == f2) {
      cout << dp[ni][nj][nk] << endl;
      return 0;
    }
    for (int k = 0; k < 4; k++) {
      int l = 0, r = K;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        int ti = ni + mid * dx[k];
        int tj = nj + mid * dy[k];
        if (valid(ti, tj) && find(ni, nj, ti, tj) == 0) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      //printf("jalan %d sejauh %d\n", k, l);
      for (int i = l; i >= 1; i--) {
        int ti = ni + i * dx[k];
        int tj = nj + i * dy[k];
        if (dp[ti][tj][k] == dp[ni][nj][nk]) break;
        if (dp[ti][tj][k] > dp[ni][nj][nk] + 1) {
          dp[ti][tj][k] = dp[ni][nj][nk] + 1;
          q.emplace(ti, tj, k);
        }
      }
    }
  }
  puts("-1");
  //cout << find(1, 1, 1, 4) << endl;
  return 0;
}
