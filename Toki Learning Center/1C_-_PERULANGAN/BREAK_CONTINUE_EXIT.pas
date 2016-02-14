Program toki_learning;
 
var
        n,i : integer;
        error : boolean;
begin
        readln(n);
        for i:=1 to n do
        begin
                if(i=93) then error := true;
                if((i mod 10 <> 0) and (error = false)) then writeln(i);
        end;
end.