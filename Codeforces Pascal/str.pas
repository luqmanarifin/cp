// 385 B

var
	i,n,cok : integer;
	ans : longint;
	a : string;

begin
	readln(a);
	n := length(a);
	ans := 0; cok := 0;
	for i:=1 to n do
		if(a[i]='b')and(a[i+1]='e')and(a[i+2]='a')and(a[i+3]='r') then begin
			ans := ans + (i-cok)*(n-i-2);
			cok := i;		
		end;
	writeln(ans);
end.