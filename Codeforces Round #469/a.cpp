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

const int N = 2e5 + 5;

char s[N];
vector<int> ans[N];
set<int> p[2];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int one = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    p[s[i] - '0'].insert(i);
    if (s[i] == '0') {
      zero++;
    } else {
      one++;
    }
  }
  int dif = zero - one;
  if (dif <= 0) {
    puts("-1");
    return 0;
  }
  bool ok = 1;
  int at = 0;
  while (!p[0].empty()) {
    int st = *(p[0].begin()), c = 0;
    while (1) {
      auto it = p[c].lower_bound(st);
      if (it == p[c].end()) break;
      st = *it;
      ans[at].push_back(st);
      p[c].erase(st);
      c ^= 1;
    }
    if (ans[at].size() % 2 == 0) {
      puts("-1");
      return 0;
    }
    at++;
  }
  if (!p[1].empty()) {
    puts("-1");
    return 0;
  }
  printf("%d\n", at);
  for (int i = 0; i < at; i++) {
    printf("%d ", ans[i].size());
    for (auto it : ans[i]) printf("%d ", it + 1); printf("\n");
  }

  return 0;
}
