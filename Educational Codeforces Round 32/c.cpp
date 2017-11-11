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

const int N = 1e5 + 5;

char s[N];
int cnt[N][26], n;

int get(int l, int r, int c) {
  return cnt[r][c] - cnt[l - 1][c];
}

bool can(int len) {
  vector<bool> ada(26, 1);
  for (int i = 1; i + len - 1 <= n; i++) {
    for (int j = 0; j < 26; j++) {
      if (get(i, i + len - 1, j) == 0) {
        ada[j] = 0;
      }
    }
  }
  for (int i = 0; i < 26; i++) if (ada[i]) return 1;
  return 0;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) cnt[i][s[i] - 'a']++;
  for (int j = 0; j < 26; j++) {
    for (int i = 1; i <= n; i++) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }
  
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
