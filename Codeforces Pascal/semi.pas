// 378 B

var
	n,k,i,q : longint;
	a,b : array[1..100000] of longint;
	aa,bb : array[1..100000] of integer;
	
function min(k : longint; a,b : array of longint; n : longint): longint;
var
	i,j,cnt : longint;
begin
	i :=k; j := k; cnt := 0;
	while(i <= n) and (j<=n) do
	begin
		inc(cnt);
		if (a[i] < b[j]) then
		begin
			if (cnt = n - 2*k) then
			begin
				min := a[i];
				break;
			end;
			inc(i);
		end else begin
			if (cnt = n - 2*k) then
			begin
				min := b[j];
				break;
			end;
			inc(j);
		end;
	end;
end;
	
begin
	readln(n);
	for i:=1 to n do readln(a[i], b[i]);
	for i:=1 to 100000 do
	begin
		if i <= n div 2 then
		begin
			aa[i] := 1;
			bb[i] := 1;
		end else begin
			aa[i] := 0;
			bb[i] := 0;
		end;
	end;
	
	k := 0;
	q := min(k,a,b,n);
	for i:= n div 2 + 1 to n do
	begin
		if(b[i] <= q) then bb[i] := 1
		else break;
	end;
	for i:= n div 2 + 1 to n do
	begin
		if(a[i] <= q) then aa[i] := 1
		else break;
	end;
	
	for i := 1 to n do write(aa[i]); writeln;
	for i := 1 to n do write(bb[i]);
end.