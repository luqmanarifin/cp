// 106 B
const
	inf = 6000;

var
	x : array[1..100,1..4] of integer;
	a : array[1..100] of boolean;
	i,j,n,min,ans : integer;
	
procedure elim;
begin
	if (x[i,1] < x[j,1]) and (x[i,2] < x[j,2]) and (x[i,3] < x[j,3]) then a[i] := false;
	if (x[i,1] > x[j,1]) and (x[i,2] > x[j,2]) and (x[i,3] > x[j,3]) then a[j] := false;
end;
	
procedure pilih;
begin
	for i:=1 to n do
		for j:=1 to 4 do
			read(x[i,j]);
	for i:=1 to n do
		for j:=i+1 to n do
			elim;
	min := inf;
	for i:=1 to n do
		if(a[i] = true) and (x[i,4] < min) then
		begin
			min := x[i,4];
			ans := i;
		end;
	writeln(ans);
end;
	
begin
	for i:=1 to 100 do a[i] := true;
	readln(n);
	pilih;
end.