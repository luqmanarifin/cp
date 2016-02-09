#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#define foreach(it, l) for (typeof(l.begin()) it = l.begin(); it != l.end(); it++)
#define db(a) cout << #a << " = " << a << endl
using namespace std;
int main() {
    int t, m, n, b, price, cant, units;
    char linea[60];
     
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
        map<string="", int> mapa_price;
        pair<int, string=""> receta;
        set< pair<int, string=""> > lista;
        gets(linea);
        int len = strlen(linea);
        transform(linea, linea + len, linea, ::toupper);
        printf("%s\n", linea); 
        scanf("%d%d%d\n", &m , &n, &b);
        for (int r = 0; r < m; r++) {
            scanf("%s %d\n", linea, &price);
            mapa_price[linea] = price;
        }
        for (int q = 0; q < n; q++) {
            gets(linea);
            receta.second = linea;
            receta.first = 0;
            gets(linea);
            cant = atoi(linea);
            units = 0;
            for (int r = 0; r < cant; r++) {
                scanf("%s %d\n", linea, &units);
                receta.first += mapa_price[linea] * units;
            }
            lista.insert(receta);
        }
        cant = 0;
        foreach(it, lista) {
            if (it->first <= b) {
            printf("%s\n", it->second.c_str());
            cant++;
            }
        }
        if(cant == 0)
            printf("Too expensive!\n");
        printf("\n");
    }
    return 0;
}