// 288A
var
	n,i : longint;
	k : integer;
	a : char;
	
procedure biasa;
begin
	for i:=1 to n do
	begin
		write(a);
		inc(a);
	end;
end;

procedure second;
begin
	write('ab');
	for i:=1 to n-k do
		if (i mod 2 = 1) then write('a')
		else write('b');
	a := 'c';
	for i:=1 to k-2 do
	begin
		write(a);
		inc(a);
	end;
end;

procedure process;
begin
	if (k > n) then writeln(-1)
	else if (k = 1) and (n > 1) then writeln(-1)
	else if (k = 1) then writeln(a)
	else if (k = n) then biasa
	else second;
end;

begin
	readln(n,k); a := 'a';
	process;
end.