Program CandyBags;

var
	i,j,n : longint;

begin
	readln(n);
	for i:=1 to n do
	begin
		for j:=1 to n do
		begin
			if (j mod 2 = 1) then write((j-1)*n+i, ' ')
			else write(j*n-i+1, ' ');
		end;
		writeln;
	end;
end.