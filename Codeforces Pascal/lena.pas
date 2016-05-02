// 118B
var
	n,i,j : integer;
	
begin
	readln(n);
	for i:=0 to n do
	begin
		for j:=1 to n-i do write('  ');
		if i = 0 then writeln(0)
		else for j:=0 to i do write(j,' ');
		if (j <> 0) then
			for j:=i-1 downto 0 do
				if j <> 0 then write(j,' ')
					else writeln(0)
	end;
	for i:=n-1 downto 0 do
	begin
		for j:=1 to n-i do write('  ');
		if i = 0 then writeln(0)
		else for j:=0 to i do write(j,' ');
		if (j <> 0) then
			for j:=i-1 downto 0 do
				if j <> 0 then write(j,' ')
					else writeln(0)
	end;
end.