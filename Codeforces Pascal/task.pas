// 118 A

var
	a : string;
	i,n : integer;
	
procedure hapus(huruf : char; var kata : string);
var
	i,n : integer;
begin
	n := length(kata);
	i := 1;
	while (i <> 0) do begin
		if (kata[i] = huruf) then delete(kata,pos(huruf,kata),1);
		i := pos(huruf,kata);
	end;
end;

begin
	readln(a);
	a := lowercase(a);
	hapus('a',a); hapus('u',a); hapus('o',a);
	hapus('i',a); hapus('e',a); hapus('y',a);
	n := length(a);
	for i:=1 to n do write('.',a[i]);
end.