Program ValeraAndPlates;

var
	n,m,k,count,tahu,tempe,i : integer;
	x : array[1..1000] of integer;

begin
	readln(n,m,k); tahu := 0; tempe := 0;
	for i:=1 to n do
	begin
		if (i <> n) then read(x[i])
		else readln(x[n]);
		if(x[i] = 1) then tahu := tahu + 1
		else tempe := tempe + 1;
	end;
	if ((k >= tempe) and (m >= tahu)) then count := 0
	else if((k >= tempe) and (m <= tahu)) then count := tahu - m
	else if ((k <= tempe) and (m >= tahu)) then count := tempe - k - (m - tahu)
	else count := tempe - k + tahu - m;
	
	if (count < 0) then writeln(0)
	else writeln(count);
end.