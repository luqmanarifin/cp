#include <bits/stdc++.h>

using namespace std;
int t, n;

char s[255];

bool yes(int k) {
	int dec[255], now;
	for(int i = 0; i<= 9; i++) {
		memset(dec, 0, sizeof dec);
		now = 0;
		for(int j = 0; j<=n-k; j++) {
			now += 10 - dec[j];
			now %= 10;
			int cur = (s[j] + now) % 10;
			dec[j+k] += i + 10 - cur;
			dec[j+k] %= 10;
			now += i + 10 - cur;
		}
		int ok = true;
		for(int j = n-k+1; j<n; j++) {
			now += 10 -dec[j];
			now %= 10;
			int cur = (s[j] + now) % 10;
			if(cur != i) {
				ok = false;
				break;
			}
		}
		if(ok)
			return true;
	}
	return false;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s);
		n = strlen(s);
		for(int i = 0; i<n; i++)
			s[i] -= '0';
    
		int ans = 1;
    for(int i = n; i >= 1; i--) {
      if(yes(i)) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
	}

	return 0;
}