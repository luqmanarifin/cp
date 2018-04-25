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

int last[N][26];
char s[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1), m;
  memset(last, -1, sizeof(last));
  scanf("%d", &m);
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      last[i][j] = last[i + 1][j];
    }
    if (i + 1 <= n) {
      last[i][s[i + 1] - 'a'] = i + 1;
    }
  }
  int now = 0;
  for (int need = m; need >= 1; need--) {
    for (int i = 0; i < 26; i++) {
      if (last[now][i] == -1) continue;
      if (n - last[now][i] + 1 >= need) {
        now = last[now][i];
        printf("%c", i + 'a');
        break;
      }
    }
  }
  printf("\n");
  return 0;
}
