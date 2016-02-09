Program PakGaus;
 
type
        jawaban = array [1..100] of integer;
var
        i,j,n,a,b,c,bil,pangkat : longint;
        x : jawaban;
 
begin
        readln(n);
        for i:=1 to n do begin
                bil := 1;
                pangkat := 1;
                readln(a,b,c);
                for j:=1 to a do
                        bil := (bil * j) mod c;
                for j:=1 to b do
                        pangkat := (pangkat mod c)*(bil mod c);
                x[i] := pangkat mod c;
        end;
        for i:=1 to n do
                writeln(x[i]);
end.