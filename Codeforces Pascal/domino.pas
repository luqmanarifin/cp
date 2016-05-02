Program adomino;

var
	x : array[1..100] of integer;
	y : array[1..100] of integer;
	i, a, b, n : integer;
	cek : boolean;

begin
	readln(n); a := 0; b := 0;
	cek := false;
	for i:=1 to n do
	begin
		readln(x[i], y[i]);
		a := a + x[i];
		b := b + y[i];
		if (((x[i] mod 2 = 1) and (y[i] mod 2 = 0)) or ((x[i] mod 2 = 0) and (y[i] mod 2 = 1))) then cek := true;
	end;
	a := a mod 2;
	b := b mod 2;
	if ((a = 1) and (b = 1) and cek) then writeln(1)
	else if ((a = 0) and (b = 0)) then writeln(0)
	else writeln(-1);
end.