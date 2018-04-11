Program toki_learning;
 
var
        bil, jumlah : longint;
begin
        while not eof(input) do
        begin
                readln(bil);
                jumlah := jumlah + bil;
        end;
        writeln(jumlah);
end.