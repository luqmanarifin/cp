Program EmpatTujuhA;

var
	n : integer;
	
begin
	readln(n);
	if (trunc(sqrt(2*n)) * (trunc(sqrt(2*n))+1) = 2*n) then writeln('YES')
	else writeln('NO');
end.