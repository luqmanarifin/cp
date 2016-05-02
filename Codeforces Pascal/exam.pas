// 194 A

var
	n,k,ans : integer;
	
begin
	readln(n,k);
	if (k div n = 2) then ans := n - k mod n
	else ans := 0;
	writeln(ans);
end.