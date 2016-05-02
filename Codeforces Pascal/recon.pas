Program Pengintaian;

var
	n,i,min,mini,temp : integer;
	a : array [0..101] of integer;
	
begin
	readln(n); min := 999; mini := 0;
	for i:=1 to n+1 do
	begin
		if (i <= n) then read(a[i]);
		a[0]:= 999 + a[1];
		a[n+1] := a[1];
		temp:= a[i] - a[i-1];
		if ((temp >= 0) and (temp < min))  then
		begin
			min := temp;
			mini := i;
		end else if ((temp < 0) and (-temp < min)) then
		begin
			min := -temp;
			mini := i;
		end;
	end;
	if (mini mod n <> 0) then writeln(mini-1, ' ', mini mod n)
	else writeln(mini-1, ' ', n);
end.			