#include <bits/stdc++.h>

using namespace std;

int xr[] = {1, 1, -1, -1};
int yr[] = {-1, 1, 1, -1};
int m[10][10];

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                m[i][j] = 0;
        bool b = false;
        int z = 0;
        for (int i = 0; i < 8; ++i) {
            ++z;
            string s;
            cin >> s;
            if (b) continue;
            int x = s[0]-'A', y = s[1]-'1';
            if (m[x][y] && m[x][y] != z) {
                b = true;
                continue;
            }
            for (int c = 0; c < 8; ++c) {
                if ((m[x][c] && m[x][c] != z) || (m[c][y] && m[c][y] != z)) {
                    b = true;
                    break;
                }
                for (int j = 0; j < 4; ++j) {
                    int xi = x + c*xr[j];
                    int yi = y + c*yr[j];
                    if (xi < 0 || xi >= 8 || yi < 0 || yi >= 8)
                        continue;
                    if (m[xi][yi] && m[xi][yi] != z) {
                        b = true;
                        break;
                    }
                }
            }
            m[x][y] = z;
        }
        if (b) puts("Invalid");
        else puts("Valid");
    }
    return 0;
}