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

const int N = 105;

int dp[N][N][2][26];
vector<pair<int, int>> edge[N];

int dfs(int a, int b, int turn, int last) {
  if (dp[a][b][turn][last] != -1) return dp[a][b][turn][last];
  set<int> s;
  if (turn == 0) {
    for (auto it : edge[a]) {
      if (it.second >= last) {
        s.insert(dfs(it.first, b, turn ^ 1, it.second));
      }
    }
  } else {
    for (auto it : edge[b]) {
      if (it.second >= last) {
        s.insert(dfs(a, it.first, turn ^ 1, it.second));
      }
    }
  }
  for (int i = 0; ; i++) {
    if (!s.count(i)) {
      return dp[a][b][turn][last] = i;
    }
  }
}

int main() {
  memset(dp, -1, sizeof(dp));
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    scanf("%d %d %c", &u, &v, &c);
    edge[u].emplace_back(v, c - 'a');
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int ret = dfs(i, j, 0, 0);
      if (ret) {
        printf("A");
      } else {
        printf("B");
      }
    }
    printf("\n");
  }
  
  return 0;
}
