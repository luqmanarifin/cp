// 181 
const
	N = 1000000007;
	M = 1000010;
	
var
	a, b : integer;
	i, t : longint;
	ans, fak : int64;
	fac : array[0..M] of int64;
	
function check(x : int64) : boolean;
begin
	while x <> 0 do begin
		if(x mod 10 <> a) and (x mod 10 <> b) then begin
			check := false;
			exit;
		end else x := x div 10;
	end;
	check := true;
end;

function power(a, b : int64): int64;
begin
	if(b = 1) then begin
		power := a;
		exit;
	end;
	if(b mod 2 = 1) then begin
		power := power(a, b-1)*a mod N;
		exit;
	end;
	power := power(a, b div 2)*power(a, b div 2);
end;

begin
	readln(a,b,t);
	fac[0] := 1;
	ans := 0;
	for i:=1 to t do fac[i] := fac[i-1]*i mod N;
	for i:=0 to t do
		if check(a*i + b*(t-i)) then begin
			fak := fac[t-i]*fac[i] mod N;
			ans := ans + (fac[t]*power(fak, N-2)) mod N;
			ans := ans mod N;
		end;
	writeln(ans);
end.
