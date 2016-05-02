Program DuaSatuEnamA;

var
	a,b,c : integer; tile : longint;

begin
	readln(a,b,c); tile := 0;
	while (a > 1) do
	begin
		tile := tile + (a*2) + (c*2-2) + ((b-2)*2);
		dec(a); dec(b); dec(c);
	end;
	tile := tile + b*c;
	writeln(tile);
end.