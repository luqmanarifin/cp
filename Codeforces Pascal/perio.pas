Program TigaTujuhSatuA;

var
	n,k,i,x,ans : integer;
	a : array[0..99] of array[1..2] of integer;

function min(a,b : integer): integer;
begin
	if (a < b) then min := a
	else min := b;
end;
	
begin
	readln(n,k); ans := 0;
	for i:=0 to 99 do
	begin
		a[i][1] := 0;
		a[i][2] := 0;
	end;
	for i:=0 to n-1 do
	begin
		read(x);
		if (x = 1) then inc(a[i mod k][1])
		else inc(a[i mod k][2]);
	end;
	for i:=0 to k-1 do
	begin
		ans := ans + min(a[i][1],a[i][2]);
	end;
	writeln(ans);
end.