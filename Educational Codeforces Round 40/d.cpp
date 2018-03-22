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

vector<int> edge[N];
bool adj[N][N];
int d[N][N];

int main() {
  int n, m, s, t;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u][v] = adj[v][u] = 1;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int st = 1; st <= n; st++) {
    for (int i = 1; i <= n; i++) d[st][i] = inf;
    d[st][st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto i : edge[now]) {
        if (d[st][i] > d[st][now] + 1) {
          d[st][i] = d[st][now] + 1;
          q.push(i);
        }
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = i; j <= n; j++) {
  //     printf("%d %d: %d\n", i, j, d[i][j]);
  //   }
  // }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!adj[i][j]) {
        bool decreased = 0;
        decreased |= (d[s][i] + d[j][t] + 1 < d[s][t]);
        decreased |= (d[t][i] + d[j][s] + 1 < d[s][t]);
        if (!decreased) {
          ans++;
          // printf("ans %d %d\n", i, j);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
