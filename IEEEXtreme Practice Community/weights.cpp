/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it,
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up, like clearing up one's heart.
I remember your smile, it floats up in my mind and I can't help but smile.
Surely, just as we were that day, like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy,
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light.
Even if you never change, even if you happen to change, you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people.
At that time, I hope we can bring along our irreplaceable families and meet here again.

Like the sky after the rain lets up, like clearing up one's heart.
I remember your smile, it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light.
We run through the passing seasons, seeing each of our many tomorrows,
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int ask(int u, int v) {
  printf("Q 2 %d %d\n", u, v);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}

int main() {
  int n;
  scanf("%d", &n);

  int A = ask(1, 2);
  int B = ask(2, 3);
  int C = ask(1, 3);
  a[1] = (A - B + C) / 2;
  a[2] = A - a[1];
  a[3] = C - a[1];
  for (int i = 4; i <= n; i++) {
    int v = ask(1, i);
    a[i] = v - a[1];
  }
  printf("A");
  for (int i = 1; i <= n; i++) printf(" %d", a[i]);
  printf("\n");
  fflush(stdout);
  return 0;
}
