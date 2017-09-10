// Author: Adrian Satja Kurdija
#include <iostream>
#include <queue>
using namespace std;

const int NN = 200200;

int izaziva[NN];
int izazvan_puta[NN];
queue<int> izazvan_od[NN];
bool kernel[NN];

void ubaci(int x);

void izbaci(int x) {
    if (!kernel[x]) return;  // vec izbacen
    kernel[x] = false;
    if (--izazvan_puta[izaziva[x]] == 0)
        ubaci(izaziva[x]);
}

void ubaci(int x) {
    if (kernel[x]) return;  // vec ubacen
    kernel[x] = true;

    while (!izazvan_od[x].empty()) {
        izbaci(izazvan_od[x].front());
        izazvan_od[x].pop();
    }

    izazvan_od[izaziva[x]].push(x);
    ++izazvan_puta[izaziva[x]];
    izbaci(izaziva[x]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i)
        cin >> izaziva[i];

    for (int i = 1; i <= 2 * n; ++i)
        if (izazvan_puta[i] == 0)
            ubaci(i);

    for (int i = 1; i <= 2 * n; ++i)
        if (kernel[i])
            cout << i << " ";
    cout << endl;
}
