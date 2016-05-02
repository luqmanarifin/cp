Program Capsiuuh;

var
	a,b, awal, hasil1, hasil2, satu, dua : string;
	n : integer;

begin
	readln(a); b := a; awal := a;
	n := length(a);
	delete(a,2,n-1); delete(b,1,1);
	a := upcase(a); b := lowercase(b);
	insert(a,b,1); hasil1 := b;
	a := lowercase(a); delete(b,1,1); b := upcase(b); 
	insert(a,b,1); satu := b; dua := upcase(b); hasil2 := lowercase(b);
	if (awal = satu) then writeln(hasil1)
	else if (awal = dua) then writeln(hasil2)
	else writeln(awal);
end.