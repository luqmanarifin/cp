Program SoftMendem;

var
	n,k,l,c,d,p,nl,np,ans : longint;
	
function min (a,b : longint): longint;
begin
	if (a < b) then min := a
	else min := b;
end;

begin
	readln(n,k,l,c,d,p,nl,np);
	ans := min((k*l) div nl, min(c*d,p div np)) div n;
	writeln(ans);
end.