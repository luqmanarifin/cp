Program toki_learning;
 
var
        n,i,j,a : integer;
begin
        readln(n);
        a := 0;
        for i:=1 to n do
        begin
                for j:=1 to i do
                begin
                        write(a mod 10);
                        a := a + 1;
                end;
                writeln;
        end;
end.