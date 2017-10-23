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

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%s %d %d", s, &a, &b);
    int n = strlen(s);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') cnta++;
      else cntb++;
    }
    queue<int> ada[2];
    while (cnta > 0) {
      int del = min(cnta, a);
      ada[0].push(del);
      cnta -= del;
    }
    while (cntb > 0) {
      int del = min(cntb, b);
      ada[1].push(del);
      cntb -= del;
    }
    int now = -1;
    if (ada[0].size() != ada[1].size()) {
      now = (ada[0].size() < ada[1].size());
      int block = ada[now].size() - 1;
      int tot = 0;
      while (ada[now ^ 1].size()) {
        tot += ada[now ^ 1].front();
        ada[now ^ 1].pop();
      }
      int rem = tot % block;
      for (int i = 0; i < rem; i++) ada[now^1].push(tot/block + 1); 
      if (tot/block) for (int i = rem; i < block; i++) ada[now^1].push(tot/block);
    } else {
      now = rand() % 2;
    }

    for (int i = 0; i < ada[now].front(); i++) printf("%c", now + 'a');
    ada[now].pop();
    
    int last = now;
    now ^= 1;
    while (ada[0].size() + ada[1].size()) {
      if (ada[now].size()) {
        if (last == now) printf("*");
        for (int i = 0; i < ada[now].front(); i++) printf("%c", now + 'a');
        ada[now].pop();
        last = now;
      }
      now ^= 1;
    }
    printf("\n");
  }

  return 0;
}
