const num = 170;

var
	n,i,j : integer;
	w : array[1..num,1..num] of integer;
	a,b : array[1..num,1..num] of real;
begin
	readln(n);
	for i:=1 to n do
		for j:=1 to n do
			read(w[i,j]);
	for i:=1 to n do
		for j:=1 to n do begin
			a[i,j] := (w[i,j]+w[j,i])/2;
			b[i,j] := (w[i,j]-w[j,i])/2;
		end;
	for i:=1 to n do begin
		for j:=1 to n do
			write(a[i,j]:0:5,' ');
		writeln;
	end;
	for i:=1 to n do begin
		for j:=1 to n do
			write(b[i,j]:0:5,' ');
		writeln;
	end;
end.