var
    S1, S2, S3, S4: string;
begin
    readln(S1);
    readln(S2);
    readln(S3);
    readln(S4);
    
    delete(S1, pos(S2, S1), length(S2));
    insert(S4, S1, pos(S3, S1) + length(S3));
    
    writeln(S1);
end.