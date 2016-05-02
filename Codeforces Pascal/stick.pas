// 394 A
var
	s : string;
	a,b,c,n,i : integer;
begin
	readln(s); n := length(s);
	a := pos('+',s)-1;
	b := pos('=',s)-2-a;