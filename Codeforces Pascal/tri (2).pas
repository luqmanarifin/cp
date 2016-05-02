var
	n : int64;
	
function f(n : int64): int64;
begin
	if(n <= 3) then f := 4 - n
	else f := (f(n-1) + f(n-2) + f(n-3))mod 1000;
end;

begin
	readln(n);
	writeln(f(n));
end.