var
	n : longint;
	a : int64;
	
function pangkat(a,b : int64): int64;
var
	temp : real;
begin
	temp := exp(b*ln(a));
	pangkat := trunc(temp);
end;
	
begin
	for n:=1 to 19 do
	begin
	if ((n > 2) and (n < 20)) then
	begin
		a := (pangkat(10,n-1) div 210 + 1)*210;
		writeln(a);
	end else writeln(-1);
	end;
end.