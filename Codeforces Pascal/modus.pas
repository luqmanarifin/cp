Program MariKitaBelajar;

var
	x : array[1..1000] of longint;
	i,b,n : longint;
	muncul, modus : longint;

begin
	for i:=1 to 1000 do x[i] := 0;
	readln(n); muncul := 0; modus := 0;
	for i:=1 to n do
	begin
		readln(b);
		x[b] := x[b] + 1;
		if(x[b] > muncul) then muncul := x[b];
	end;
	for i:=1 to 1000 do
	begin
		if((x[i] = muncul) and (i > modus)) then modus := i;
	end;
	writeln(modus);
end.