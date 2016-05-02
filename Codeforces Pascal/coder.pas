// 384 A

var
	n,i,j : integer;
	
begin
	readln(n);
	if(n mod 2 = 0)then
	begin
		writeln(n div 2 * n);
		for i:=1 to n do begin
			for j:=1 to n div 2 do
				if(i mod 2 = 1) then write('C.')
				else write('.C');
			writeln;
		end;
	end else begin
		writeln((n div 2)*(n div 2) + (n div 2 + 1)*(n div 2 + 1));
		for i:=1 to n do begin
			for j:=1 to n do
				if(i mod 2 = j mod 2) then write('C')
				else write('.');
			writeln;
		end;
	end;
end.