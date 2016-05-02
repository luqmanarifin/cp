// B

var
	n,i,j,coin : integer;
	a : array[-298..599] of integer;
	
procedure next;
var
	k,b : integer;
begin
	i := j;
	k := 0;
	repeat
		inc(k);
		if (k mod 2 = 1) then j := i + (k + 1) div 2
		else  j := i - k div 2;
		if (j = 599) and (a[1] = 0) then j := i;
		if (j = -298) and (a[n] = 0) then j := i;
	until(a[j] <> 0);
	if (j > i) then
	begin
		for b:=1 to j-i do write('R');
		write('P');
	end else if (j < i) then 
	begin
		for b:=1 to i-j do write('L');
		write('P');
	end else if (j = 1) then
		write('RLP')
	else write('LRP');
	dec(a[j]);
	dec(coin);
end;
	
begin
	readln(n);
	for i:=-298 to 599 do a[i] := 0;
	coin := 0;
	for i:=1 to n do
	begin
		read(a[i]);
		coin := coin + a[i];
	end;

	if (a[1] <> 0) then
	begin
		write('P');
		dec(coin);
		dec(a[1]);
	end;
		
	j := 1;
	while(coin > 0) do next;
end.
	