// 368 B
var
	n,m,i : longint;
	a,l,t,ans : array[1..1000001] of longint;
begin
	readln(n,m);
	for i:=1 to n do read(a[i]);
	ans[n+1] := 0;
	for i:=n downto 1 do begin
		if(t[a[i]] = 0) then ans[i]:=ans[i+1]+1
		else ans[i]:=ans[i+1];
		t[a[i]] := 1;
	end;
	for i:=1 to m do readln(l[i]);
	for i:=1 to m do writeln(ans[l[i]]);
end.