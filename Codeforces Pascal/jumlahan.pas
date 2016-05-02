program ideone;

var
	n, sum, hasil : int64;
	i : longint;
	
function power (number : int64 ; exponent: longint): int64;
var
	temp : real;
begin
	temp := Exp(Exponent*Ln(Number));
	power := trunc(temp);
end; 

begin
	n := 0; sum := 0;
	for i:=1 to 2013 do
	begin
		if (i <= 11) then 
			n := n mod power(10,11) + power(10,i-1) mod power(10,11);
		sum := (sum + n) mod power(10,11);
	end;
	writeln(sum);
	
	hasil := 0;
	for i:=1 to 11 do
	begin
		hasil := hasil +(sum mod power(10,i)) div power(10,i-1);
		sum := sum - sum mod power(10,i);
	end;
	writeln(hasil);
end.