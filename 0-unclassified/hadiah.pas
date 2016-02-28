    program mabokHadiah;
     
    var	f: array[ 0..5 ] of longInt;
     
    function phi( num: longInt ): longInt;
    var	i, res: longInt;
    begin
    res := num;
    i := 2;
    while ( i * i <= num ) do
    begin
    if ( num mod i = 0 ) then
    dec( res, res div i );
    while ( num mod i = 0 ) do
    num := num div i;
    inc( i );
    end;
    if ( num > 1 ) then
    dec( res, res div num );
    exit( res );
    end;
     
    function montgomery( p, q, r: longInt ): longInt;
    var	res: longInt;
    begin
    res := 1;
    while ( q > 0 ) do
    begin
    if odd( q ) then
    res := res * p mod r;
    q := q div 2;
    p := p * p mod r;
    end;
    exit( res );
    end;
     
    function dfs( cur, n: longInt ): longInt;
    var	tmp, res: longInt;
    begin
    if ( cur = 2 ) then
    exit( f[cur] mod n );
    exit( montgomery( f[cur], dfs( cur + 1, phi(n) ) + phi(n), n ) );
    end;
     
    var	n: longInt;
     
    begin
    readln( f[0], f[1], f[2], n );
    writeln( dfs(0, n) + 1 );
    end.