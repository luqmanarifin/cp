unit railroad;

interface

type
    TIntArray = array of longint;

function plan_roller_coaster(s, t : TIntArray) : Int64;

implementation

function plan_roller_coaster(s, t : TIntArray) : Int64;
var 
    n : Longint;
begin
    n := Length(s);
    plan_roller_coaster := 0;
end;

end.
