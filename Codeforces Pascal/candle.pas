// A

var
	a,b,ans : longint;
	
begin
	readln(a,b);
	ans := a;
	repeat
		ans := ans + a div b;
		a := a div b + a mod b;
	until (a < b);
	writeln(ans);
end.