Program KadalBonek;

var
	a,b,c,d : integer;

begin
	readln(a,b,c,d);
	if ((a = c) or (b = d)) then write('1 ')
	else write('2 ');
	
	if (((a = c) and ((b - d) mod 2 = 0)) or ((b = d) and ((a - c) mod 2 = 0))) then write('2 ')
	else if ((a = c) or (b = d)) then write('0 ')
	else if (((a-c)/(b-d)=1) or ((a-c)/(b-d)=-1)) then write('1 ')
	else if (((a-c) mod 2 - (b-d) mod 2) mod 2 = 0) then write('2 ')
	else write('0 ');
	
	if((a >= c)and(b >= d)) then
		if(a - c > b - d) then writeln(a - c)
		else writeln(b - d)
	else if((a >= c)and(b <= d)) then
		if(a - c > d - b) then writeln(a - c)
		else writeln(d - b)
	else if((a <= c)and(b >= d))then
		if(c - a > b - d) then writeln(c - a)
		else writeln(b - d)
	else
		if(c - a > d - b) then writeln(c - a)
		else writeln(d - b);
end.