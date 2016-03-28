#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int inf = 1e6+5;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(inf);
        while (n--) {
            int x; scanf("%d", &x); v[x]++;
        }
        long long ans = 0;
        for (int i = 2; i < inf; ++i) {
            if (v[i]) ans += (v[i]-1)*v[i]/2;
            else continue;
            for (int j = i << 1; j < inf; j += i) {
                if (v[j]) {
                    ans += v[j]*v[i];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}