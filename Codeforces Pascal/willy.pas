Program chillyiuh;

var
	n,a,i : longint;
	
begin
	readln(n); a := n mod 6;
	if((n=1)or(n=2)) then writeln('-1')
	else if (n = 3) then writeln('210')
	else begin
		write(1);
		for i:=5 to n do write('0');
		if(a = 4) then write('05')
		else if (a = 5) then write('08')
		else if (a = 0) then write('17')
		else if (a = 1) then write('02')
		else if (a = 2) then write('20')
		else write('11');
		writeln('0');
	end;
end.