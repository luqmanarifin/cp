function swag(x:integer):integer;
begin
if (x<7) then swag:=x
else swag:=swag(x mod 7)*swag(x div 7)*7;
end;

begin
writeln(swag(71));
end.