Program KursiKonser;

var
	n,m,k : integer;
	a,b : integer;

begin
	readln(n,m,k);
	b := 0;
	if (k mod m = 0) then
	begin
		a := k div b;
		b := m;
	end else begin
		a := k div m + 1;
		b := k mod m;
	end;
	writeln(a,' ', b);
end.
	