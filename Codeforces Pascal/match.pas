// 159 B
var
	n,m,i,j,clo,bea : longint;
	b,y : array[1..1000] of longint;
	aa,bb,xx,yy : array[1..100000] of integer;
	
function min(a,b : longint): longint;
begin
	if(a < b) then min := a
	else min := b;
end;

function max(a,b : longint): longint;
begin
	if(a < b) then max := b
	else max := a;
end;
	
begin
	readln(n,m);
	for i:=1 to 1000 do begin
		b[i] := 0;
		y[i] := 0;
	end;
	for i:=1 to n do
	begin
		read(xx[i]);
		readln(yy[i]);
		inc(y[yy[i]]);
	end;
	for i:=1 to m do begin
		read(aa[i]);
		readln(bb[i]);
		inc(b[bb[i]]);
	end;
	clo := 0; bea := 0;
	for i:=1 to 1000 do
		clo := clo + min(b[i],y[i]);
	for i:=1 to n do
		for j:=1 to m do
			if(xx[i] = aa[j]) and (yy[i] = bb[j]) then begin
				inc(bea);
				break;
			end;
	writeln(clo,' ',bea);
end.
	