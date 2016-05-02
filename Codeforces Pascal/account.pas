Program doriuh;

var
	a,b,n : integer; x : real;
	
begin
	readln(a,b,n);
	if ((a = 0) and (b = 0)) then writeln(5)
	else if (a = 0) then writeln('No solution')
	else if (b = 0) then writeln(0)
	else if (b/a < 0) and (n mod 2 = 0) then writeln('No solution')
	else if (b/a < 0) then 
	begin
		x := exp(1/n * ln(-b div a));
		if (trunc(x) = x) then writeln(-trunc(x))
		else writeln('No solution');
	end
	else begin
		x := exp(1/n * ln(b div a));
		if (trunc(x) = x) then writeln(trunc(x))
		else writeln('No solution');
	end;
end.