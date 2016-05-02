Program Equation;

var
	a,i,sum: int64;
	cek : boolean;
	
function digit(a : int64): int64;
var
	i : integer;
begin
	digit := 0;
	for i:=1 to 18 do
	begin
		digit := digit + a mod 10;
		a := (a - a mod 10) div 10;
	end;
end;

begin
	readln(a); cek := false; i := 1;
	while((i <= trunc(sqrt(a))) and not(cek)) do
	begin
		sum := digit(i);
		if (i*i + sum*i = a) then cek := true
		else i := i + 1;
	end;
	if (cek) then writeln(i)
	else writeln(-1);	
end.
	