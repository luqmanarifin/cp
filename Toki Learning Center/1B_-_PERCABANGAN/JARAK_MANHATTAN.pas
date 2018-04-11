Program p259;
 
var
        a,b,c,d,jarak : longint;
begin
        readln(a,b,c,d);
        if(a > c) then jarak := a - c
        else jarak := c - a;
        if(b > d) then jarak := jarak + b - d
        else jarak := jarak + d - b;
        writeln(jarak);
end.