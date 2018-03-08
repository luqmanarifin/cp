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
int cnt[10], ans[10];

void print(int n) {
  while (n--) printf("9"); printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    if (n % 2) {
      print(n - 1);
      continue;
    }
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
    bool found = 0;
    for (int i = n - 1; i >= 0; i--) {
      cnt[s[i] - '0']--;
      int free = n - i - 1;
      for (int j = s[i] - '0' - 1; j >= 0; j--) {
        if (j == 0 && i == 0) continue;
        cnt[j]++;
        
        int single = 0;
        for (int k = 0; k <= 9; k++) if (cnt[k] % 2) single++;
        int need = single;
        if (need <= free) {
          //printf("found %d %d\n", i, j);
          for (int it = 0; it < i; it++) printf("%c", s[it]);
          printf("%d", j);
          for (int k = 0; k <= 9; k++) {
            if (cnt[k] % 2) {
              free--;
              ans[k]++;
            }
          }
          ans[9] += free;
          for (int k = 9; k >= 0; k--) while (ans[k]--) printf("%d", k);
          printf("\n");
          found = 1;
          goto niki;
        }
        
        cnt[j]--;
      }
    }
    niki:;
    if (!found) print(n - 2);
  }

  return 0;
}
