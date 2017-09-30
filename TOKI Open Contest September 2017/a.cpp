/*

With our small shoulders next to each others,
we walked all alone
For a mere trivial matter, we burst in laughter
And also gazed for the same dreams
If I listen carefully, 
even now I still could hear
your voice is resounding 
in the middle of 
this orange-colored town

It's so boring, 
when you're nowhere
If I said I felt lonely, 
you'd laugh after me
But countless times, 

I've ensured
all things you left behind won't vanish, 
they'll continue to sparkling beautifully

I’ll smile in no time, 
if I remember, recall your smiling faces
Just like after rain sky,
relieves all troubles from my heart

I believe, 
we’ll be the same like those old days
still like innocent children
Run and dash away after the cycle of seasons
Face tomorrows of our own

If I was all alone, I felt uneasy
Sleepless nights, you were always by my side
kept telling me your story

What matters 
will you face from now on?
And also, 
what matters will I face from here?
Secretly, I try to entrust my tears
along with the setting down twilight
in the middle of this orange-colored town

In the midst of millions rays
was born a glimmer of love
Even though you’ve changed
or still the way you’re
You’re still yourself
Nothing to be worried of

It would be nice, 
if someday we’ve been adults
encountered 
our dearest one,
brought along 
our irreplaceable families
and could meet again here, 
in this place

I’ll smile in no time, 
if I remember, recall your smiling faces
Just like after rain sky,
relieves all troubles from my heart

In the midst of millions rays
was born a glimmer of love
Run and dash away after the cycle of seasons
Face tomorrows of our own
Choose dreams of our own

*/

#include <bits/stdc++.h>

using namespace std;

int a[10];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 8; i++) a[i - 1] = i;
  do { 
    if (n == 0) break;
    int l = a[0] * 10 + a[1];
    int r = a[2] * 10 + a[3];
    int h = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
    if (l * r == h) {
      printf("%d%dx%d%d=%d%d%d%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
      n--;
    }
  } while (next_permutation(a, a + 8));
  return 0;
}
