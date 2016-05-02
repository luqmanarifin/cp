//2A

var
	n,i,maxi,j : integer;
	max : int64;
	m : string;
	x : array [1..1001] of string;
	a : array [1..1001] of int64;
	
procedure pisah(var i,maxi : integer; var max : int64; var a : array of int64; var x : array of string; m : string);
var
	temp : string;
	n : int64;
begin
	temp := m;
	delete(m,pos(' ',m),5);
	delete(temp,1,pos(' ',temp));
	val(temp,n);
	i := 1;
	while not((x[i] = m) or (x[i] = '')) do i := i + 1;
	x[i] := m;
	a[i] := a[i] + n;
	if (a[i] > max) then
	begin
		max := a[i];
		maxi := i;
	end;
end;
	
begin
	readln(n); max := 0;
	for i:=1 to 1000 do
	begin
		x[i] := '';
		a[i] := 0;
	end;
	for i:=1 to n do
	begin
		readln(m);
		pisah(j,maxi,max,a,x,m);
	end;
	writeln(x[maxi+1]);
end.
		