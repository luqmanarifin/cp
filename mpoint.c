#include <stdio.h>
#include <stdbool.h>
#include "point.h"

int main() {
	int x,y;
	POINT P, Q;

	scanf("%d%d", &x, &y);
	P = MakePoint(x,y);
	TulisPoint(P);
	BacaPoint(&P);
	TulisPoint(P);
	printf("X = %lf Y = %lf\n", GetAbsis(P), GetOrdinat(P));
	SetAbsis(&P, 1);
	SetOrdinat(&P,0);
	TulisPoint(P);
	if (IsOrigin(P)) puts("True"); else puts("False");
	if (IsOnSbX(P)) puts("True"); else puts("False");
	if (IsOnSbY(P)) puts("True"); else puts("False");
	// Cek Kuadran
	Geser(&P,0,5);
	printf("%d\n", Kuadran(P));
	TulisPoint(MirrorOf(P, true));
	BacaPoint(&Q);
	if (EQ(P,Q)) puts("Equal");
	if (!NEQ(P,Q)) puts("Not Equal");
	printf("%lf %lf\n", Jarak0(P), Panjang(P,Q));
	Putar(&P,120);
	TulisPoint(P);
}