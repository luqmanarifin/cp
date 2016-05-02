Program SatuEmpatDelapanA;

var
	k,l,m,n,d,i,c	: longint;

procedure habis(k,l,m,n,d : longint; var c: longint);
begin
	if ((d mod k =0) or (d mod l = 0) or(d mod m = 0)or(d mod n = 0)) then c := c + 1;
end;

begin
	readln(k,l,m,n,d); c := 0;
	for i:=1 to d do habis(k,l,m,n,i,c);
	writeln(c);
end.