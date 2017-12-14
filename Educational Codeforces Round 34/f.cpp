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
const int STATE = 300;

int dp[N][STATE];
int p[5], be[5], lo[5];

void decompile(int base, int val) {
  for (int i = 0; i < 4; i++) {
    p[i] = base + val % 4;
    val /= 4;
  }
}

pair<int, int> compile(int* a) {
  int mini = inf, val = 0, maxi = -inf;
  for (int i = 0; i < 4; i++) mini = min(mini, a[i]);
  for (int i = 0; i < 4; i++) maxi = max(maxi, a[i]);
  if (maxi - mini > 3) return {-1, -1};
  for (int i = 3; i >= 0; i--) {
    val = val * 4 + (a[i] - mini);
  }
  return {mini, val};
}

char s[5][N];
int cost[5], n, sum[5][N];

int find(int i, int l, int r) {
  return sum[i][r] - sum[r][l - 1];
}

void upd(int& at, int val) {
  at = min(at, val);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 4; i++) scanf("%d", cost + i);
  for (int i = 0; i < 4; i++) scanf("%s", s[i] + 1);
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= n; j++) {
      sum[i][j] = sum[i][j - 1] + (s[i][j] == '*');
    }      
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < STATE; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < STATE; j++) {
      if (dp[i][j] == inf) continue;
      decompile(i, j);
      //for (int k = 0; k < 4; k++) printf("%d ", p[k]); printf(": %d\n", dp[i][j]);
      
      // kosongan, langsung
      for (int k = 0; k < 4; k++) {
        if (p[k] + 1 <= n && s[k][p[k]+1] == '.') {
          p[k]++;
          auto it = compile(p);
          if (it.first == -1) continue;
          upd(dp[it.first][it.second], dp[i][j]);
          p[k]--;
        }
      }
      
      for (int size = 1; size <= 4; size++) {
        for (int pi = 0; pi <= 4 - size; pi++) {
          for (int pj = min(n, i + size); pj > i; pj--) {
            if (pj < size) continue;
            for (int k = 0; k < 4; k++) {
              if (pi <= k && k < pi + size) {
                be[k] = pj;
                lo[k] = pj - size + 1;
              } else {
                be[k] = p[k];
                lo[k] = p[k];
              }
            }
            bool ok = 1;
            for (int k = 0; k < 4; k++) {
              if (p[k] + 1 < lo[k]) {
                if (find(k, p[k] + 1, lo[k] - 1)) {
                  ok = 0;
                  break;
                }
              }
            }
            if (!ok) continue;
            auto it = compile(be);
            if (it.first == -1) continue;
            upd(dp[it.first][it.second], dp[i][j] + cost[size]);
          }
        }
      }
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}
