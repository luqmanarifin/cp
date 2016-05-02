Program TigaEnamEnamA;

var
	a,b,c,d,n,i	: longint;

function min(a,b : longint) : longint;
begin
	if (a < b) then min :=a
	else min := b;
end;

begin
	readln(n);
	for i:=1 to 4 do
	begin
		readln(a,b,c,d);
		if (min(a,b)+min(c,d) <= n) then
		begin
			writeln(i,' ',min(a,b), ' ',n-min(a,b));
			halt(0);
		end;
	end;
	writeln(-1);
end.