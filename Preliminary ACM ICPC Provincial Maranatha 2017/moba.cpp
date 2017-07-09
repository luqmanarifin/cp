#include <bits/stdc++.h>

using namespace std;

int cap[10][10];
int ans[2];
int main()
{
	int ntc;
	cin >> ntc;

	while (ntc--) {
		string s[2];
		for (int l = 0; l < 2; ++l) {
			cin >> s[l];
			ans[l] = 0;
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 4; ++j) {
					cin >> cap[i][j];
				}
			}
			/* for (int i = 0; i < 5; ++i) { */
			/* 	for (int j = 0; j < 4; ++j) { */
			/* 		cout << cap[i][j] << " "; */
			/* 	} */
			/* 	cout << endl; */
			/* } */
			/* cout << endl; */
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					for (int k = 0; k < 5; ++k) {
						if (i != j && i != k && j != k) {
							/* printf("%d %d %d\n", i, j, k); */
							/* printf("%d %d %d\n", cap[i][0], cap[j][1], cap[k][2]); */
							int sup = 0;
							for (int p = 0; p < 5; ++p) {
								if (p != i && p != j && p != k)
									sup += cap[p][3];
							}
							/* printf("L = %d Sup %d\n", l, sup); */
							ans[l] = max(ans[l], sup+cap[i][0]+cap[j][1]+cap[k][2]);
						}
					}
				}
			}
		}
		if (ans[0] == ans[1]) cout << "50-50" << endl;
		else if (ans[0] > ans[1]) cout << s[0] << endl;
		else cout << s[1] << endl;
	}

	return 0;
}
