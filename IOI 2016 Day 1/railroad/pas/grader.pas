uses railroad;

var i, n : Longint;
    s, t : TIntArray;
    answer : int64;

begin
    read(n);
    setLength(s, n);
    setLength(t, n);
    for i := 0 to n - 1 do
        read(s[i], t[i]);
    answer := plan_roller_coaster(s, t);
    writeln(answer);
end.
