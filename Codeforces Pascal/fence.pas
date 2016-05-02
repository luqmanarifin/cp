Program DuaTujuhKosongA;
var
	n,i : longint;
	a : array[1..179] of longint;
	
begin
	readln(n);
	for i:=1 to n do readln(a[i]);
	for i:=1 to n do
	begin
		if(2*a[i] div (180-a[i]) = 2*a[i]/(180-a[i])) then writeln('YES')
		else writeln('NO');
	END;
END.