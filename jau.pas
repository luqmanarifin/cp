program lipatkertas;
 
var
n,i,j,a,b,c,d:longint;
s:ansistring;
kertas:array[1..100000] of longint;
 
begin
readln;
readln(n);
for i := 1 to n do begin
read(j);
kertas[j] := i;
end;
a := kertas[1];
b := kertas[2];
c := kertas[3];
d := kertas[4];
s := '';
for i := 1 to n-1 do begin
if (i mod 2 = 1) and (((kertas[i] < a) and (kertas[i+1] > a) and (kertas[i+1] < b)) or ((kertas[i] > a) and (kertas[i] < b) and (kertas[i+1] < a)) or ((kertas[i] < b) and (kertas[i] > a) and (kertas[i+1] > b)) or ((kertas[i] > b) and (kertas[i+1] < b) and (kertas[i+1] > a))) then begin
//writeln(i,' ',kertas[i],' ',kertas[i+1],' ',a,' ',b);
writeln('INVALID');
exit;
end else if (i mod 2 = 0) and (((kertas[i] < c) and (kertas[i+1] > c) and (kertas[i+1] < d)) or ((kertas[i] > c) and (kertas[i] < d) and (kertas[i+1] < c)) or ((kertas[i] < d) and (kertas[i] > c) and (kertas[i+1] > d)) or ((kertas[i] > d) and (kertas[i+1] < d) and (kertas[i+1] > c))) then begin
//writeln(i,' ',kertas[i],' ',kertas[i+1],' ',c,' ',d);
writeln('INVALID');
exit;
end;
if i mod 2 = 1 then begin
if kertas[i+1] > kertas[i] then begin
s := s + 'B';
a := kertas[i];
b := kertas[i+1];
end else begin
s := s + 'A';
a := kertas[i+1];
b := kertas[i];
end;
end else begin
if kertas[i+1] < kertas[i] then begin
s := s + 'B';
c := kertas[i+1];
d := kertas[i];
end else begin
s := s + 'A';
c := kertas[i];
d := kertas[i+1];
end;
end;
end;
writeln(s);
end.