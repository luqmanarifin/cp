Program toki_learning;
 
var
        n, bebek, jumlah,i : longint;
begin
        read(n);
        for i:=1 to n do
        begin
                read(bebek);
                jumlah := jumlah + bebek;
        end;
        writeln(jumlah);
end.