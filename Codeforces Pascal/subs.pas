// 386 C

var
	a : ansistring;
	i,j,k,n,q : longint;
	ans,x : array[0..25] of longint;
	
function mean(g : char): longint;
begin
	case g of
	'a' : mean := 0;
	'b' : mean := 1;
	'c' : mean := 2;
	'd' : mean := 3;
	'e' : mean := 4;
	'f' : mean := 5;
	'g' : mean := 6;
	'h' : mean := 7;
	'i' : mean := 8;
	'j' : mean := 9;
	'k' : mean := 10;
	'l' : mean := 11;
	'm' : mean := 12;
	'n' : mean := 13;
	'o' : mean := 14;
	'p' : mean := 15;
	'q' : mean := 16;
	'r' : mean := 17;
	's' : mean := 18;
	't' : mean := 19;
	'u' : mean := 20;
	'v' : mean := 21;
	'w' : mean := 22;
	'x' : mean := 23;
	'y' : mean := 24;
	'z' : mean := 25;
	end;
end;

procedure clear;
var	m : longint;
begin
	for m:=0 to 25 do x[m]:=0;
end;

procedure find;
begin
	if(x[mean(a[j])]=0)then begin
		inc(k);
		x[mean(a[j])] := 1;
	end;
	inc(ans[k]);
	inc(j);
	if(j <= n-i+1) then find;
end;

procedure findown;
begin
	if(x[mean(a[j])]=0)then begin
		inc(k);
		x[mean(a[j])] := 1;
	end;
	inc(ans[k]);
	dec(j);
	if(i < j) then findown;
end;

begin
	readln(a); n := length(a); q := n div 2; i:=1;
	while(i <= q) do begin
		k := -1; clear; j := i; find;
		k := -1; clear; j := n - i + 1; findown; inc(i);
	end;
	if(n mod 2 = 1) then inc(ans[0]);
	n := 0;
	for i:=0 to 25 do
		if(ans[i]<>0) then inc(n);
	writeln(n);
	for i:=0 to n-1 do writeln(ans[i]);
end.