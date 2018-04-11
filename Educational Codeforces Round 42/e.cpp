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

long long x[N];
int d[N];
char c[N];
int s[N][3], f[N][3];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld %c", x + i, c + i);
  for (int i = 1; i <= n; i++) {
    if (c[i] == 'R') d[i] = 0;
    else if (c[i] == 'B') d[i] = 1;
    else d[i] = 2;
    
    s[i][d[i]]++;
    for (int j = 0; j < 3; j++) s[i][j] += s[i-1][j];
  }
  for (int i = n; i >= 1; i--) {
    f[i][d[i]]++;
    for (int j = 0; j < 3; j++) f[i][j] += f[i+1][j];
  }
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    long long dist = x[i] - x[i-1];
    if (d[i] + d[i-1] == 1) {
      int kali = 0;
      kali += !!f[i][d[i-1]];
      kali += !!s[i-1][d[i]];
      ans += kali * dist;
    } else if (d[i] + d[i-1] == 4) {
      ans += dist;
    } else {
      int kali = 1;
      if (d[i-1] <= 1) {
        if (s[i-1][d[i-1]^1] && f[i][d[i-1]^1]) {
          //printf("lef %d %d\n", s[i-1][d[i-1]], f[i][d[i-1]]);
          kali = 2;
        }
      }
      if (d[i] <= 1) {
        if (s[i-1][d[i]^1] && f[i][d[i]^1]) {
          //printf("rig %d %d\n", s[i-1][d[i]], f[i][d[i]]);
          kali = 2;
        }
      }
      ans += dist * kali;
    }
    //cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
