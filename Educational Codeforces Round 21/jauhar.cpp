#include <bits/stdc++.h>

using namespace std;

int n, a[100000];
set<long long> s;
map<long long,int> last;
long long sum, temp;

int main() {
	scanf("%d", &n);
	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		last[a[i]] = i;
		sum += (long long) a[i];
	}
	
	if (sum % 2LL == 0) {
		temp = 0;
		for (int i = 0; i < n; i++) {
			temp += (long long) a[i];
			s.insert(a[i]);

			if (temp == sum / 2LL
				|| (temp > sum / 2LL && s.find(temp - sum / 2LL) != s.end())
				|| (temp < sum / 2LL && last[sum / 2LL - temp] > i)) {
          cout << i << endl;
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");

	return 0;
}