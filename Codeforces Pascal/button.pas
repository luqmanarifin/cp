// 268 B

var
	i,ans,n : integer;
	
begin
	readln(n);
	ans := 0;
	for i:=1 to n do
		ans := ans + (n-i)*i;
	ans := ans + n;
	writeln(ans);
end.