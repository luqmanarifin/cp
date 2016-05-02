Program IlyaAndBank;

var
	kata, pas, cungul : string;
	angka, n, a, b : longint;

begin
	readln(angka);
	str(angka, kata); n := length(kata); pas := kata; cungul := kata;
	delete(pas,n,1); delete(cungul, n-1, 1);
	val(pas,a); val(cungul,b);
	if(angka >= 0) then writeln(angka)
	else begin
		if(a > b) then writeln(a) else writeln(b);
	end;
end.