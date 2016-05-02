Program WIzardan;

var
	n,x,y,c : longint;

begin
	readln(n,x,y);
	if ((n*y) mod 100 = 0) then c := y*n div 100 - x
	else c := trunc(y/100*n) + 1 - x;
	if (c < 0) then writeln(0)
	else writeln(c);
end.