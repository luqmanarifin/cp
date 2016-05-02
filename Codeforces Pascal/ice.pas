// 158 D

var
	n,ans,sum : int64;
	i,j : longint;
	t : array[0..19999] of int64;

procedure dor(n,grup,index : int64; t : array of int64; var ans : int64);
var
	a,minus : longint;
begin
	minus := 0;
	a := index-1;
	while a <= n do
	begin
		minus := minus + t[a];
		a := a + grup;
	end;
	if minus > ans then ans := minus;
end;
	
begin
	readln(n); sum := 0;
	for i:=0 to n-1 do
	begin
		read(t[i]);
		sum := sum + t[i];
	end;
	i := 2; ans := sum;
	while(i < n) do begin
		if (n div i >= 3) and (n mod i = 0) then begin
			for j :=1 to i do begin
				dor(n,i,j,t,ans);
			end;
		end;
		inc(i);
	end;
	writeln(ans);
end.