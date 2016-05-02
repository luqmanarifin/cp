Program TigaDuaDuaB;

var
	r,g,b,count,j,k,t : int64;

function min(a,b: int64) : int64;
begin
	if (a < b) then min := a
	else min := b;
end;

procedure dor(var a : int64; var b : int64);
begin
	if(a=0) then
	begin
		a := 3;
		b := b - 1;
	end;
end;

begin
	readln(r,g,b); j := r mod 3; k := g mod 3; t:= b mod 3;
	count := r div 3 + g div 3 + b div 3;
	if (r <> 0) then dor(j,count);
	if (g <> 0) then dor(k,count);
	if (b <> 0) then dor(t,count);
	count := count + min(j,min(k,t));
	if((r mod 3 = 0) and (g mod 3=0) and (b mod 3=0)) then writeln(r div 3 + g div 3 + b div 3)
	else if((j+k+t=7) and ((j=1) or(k=1)or(t=1))) then writeln(count + 1)
	else writeln(count);
end.