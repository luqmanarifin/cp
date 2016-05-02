Program SatuDuaTujuhB;

var
	n,i,sum,x : integer;
	a : array[1..100] of integer;
	
begin
	for i:=1 to 100 do a[i] := 0;
	readln(n); sum := 0; 
	for i:=1 to n do
	begin
		read(x);
		inc(a[x]);
	end;
	for i:=1 to 100 do sum := sum + a[i] div 2;
	writeln(sum div 2);
end.