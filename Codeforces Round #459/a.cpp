/*

Every day, I imagine a future where I can be with you
In my hand is a pen that will write a poem of me and you
The ink flows down into a dark puddle
Just move your hand - write the way into his heart!
But in this world of infinite choices
What will it take just to find that special day?
What will it take just to find that special day?

Have I found everybody a fun assignment to do today?
When you're here, everything that we do is fun for them anyway
When I can't even read my own feelings
What good are words when a smile says it all?
And if this world won't write me an ending
What will it take just for me to have it all?

Does my pen only write bitter words for those who are dear to me?
Is it love if I take you, or is it love if I set you free?
The ink flows down into a dark puddle
How can I write love into reality?
If I can't hear the sound of your heartbeat
What do you call love in your reality?
And in your reality, if I don't know how to love you
I'll leave you be

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N];
int can[N][N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      can[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    int now = 0, ask = 0;
    for (int j = i; j <= n; j++) {
      if (s[j] == '(') {
        now++;
      } else if (s[j] == ')') {
        now--;
      } else {
        ask++;
      }
      if (now < 0) {
        if (ask == 0) {
          for (int k = j; k <= n; k++) {
            can[i][k] = 0;
          }
          break;
        } else {
          ask--;
          now++;
        }
      }
      if ((j - i) % 2 == 0 || ask < now) {
        can[i][j] = 0;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    int now = 0, ask = 0;
    for (int j = i; j >= 1; j--) {
      if (s[j] == '(') {
        now--;
      } else if (s[j] == ')') {
        now++;
      } else {
        ask++;
      }
      if (now < 0) {
        //printf("minus %d %d\n", j, i);
        if (ask == 0) {
          for (int k = j; k >= 1; k--) {
            can[k][i] = 0;
          }
          break;
        } else {
          ask--;
          now++;
        }
      }
      if ((i - j) % 2 == 0 || ask < now) {
        can[j][i] = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (can[i][j]) {
        //printf("%d %d\n", i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
