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

const int N = 3e5 + 5;
const int MAGIC = 320;

int a[N], p[N];
long long s[N], k;

long long now;
int l, r;

vector<long long> all;
int at[N], atp[N], atm[N], cnt[N];

void add(int i, int v) {
  cnt[at[i]] += v;
}

long long ans[N];

int main() {
  int n;
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s[i] = s[i - 1] + (p[i] == 1? a[i] : -a[i]);
  }
  for (int i = 0; i <= n; i++) {
    all.push_back(s[i]);
    all.push_back(s[i] + k);
    all.push_back(s[i] - k);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i <= n; i++) {
    at[i] = lower_bound(all.begin(), all.end(), s[i]) - all.begin();
    atp[i] = lower_bound(all.begin(), all.end(), s[i] + k) - all.begin();
    atm[i] = lower_bound(all.begin(), all.end(), s[i] - k) - all.begin();
  }

  // block - r - l - id
  vector<tuple<int, int, int, int>> que;
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    que.emplace_back(u / MAGIC, v, u, i);
  }
  sort(que.begin(), que.end());
  l = r = 1;
  now = (s[1] == k);
  add(1, 1);
  for (auto it : que) {
    int u, v, id;
    tie(ignore, v, u, id) = it;
    //printf("jawab %d: %d %d\n", id, u, v);

    while (r < v) {
      add(r + 1, 1);
      now += cnt[atm[r + 1]];
      if (s[l - 1] == s[r + 1] - k) now++;
      if (s[r + 1] == s[r + 1] - k) now--;
      r++;
    }
    while (u < l) {
      add(l - 1, 1);
      now += cnt[atp[l - 2]]; 
      l--;
    }
    while (v < r) {
      now -= cnt[atm[r]];
      if (s[l - 1] == s[r] - k) now--;
      if (s[r] == s[r] - k) now++;
      add(r, -1);
      r--;
    }
    while (l < u) {
      now -= cnt[atp[l - 1]];
      add(l, -1);
      l++;
    } 
    ans[id] = now;
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
