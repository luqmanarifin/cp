    procedure print(mString:string);
    begin
        write(mString);
    end;

    procedure print(mJam:Jam);
    begin
        with mJam do
        begin
            if (hh >= 0) then write(hh div 10, hh mod 10) else write('__');
            write(':');
            if (mm >= 0) then write(mm div 10, hh mod 10) else write('__');
        end;
    end;

    procedure print(mTanggal:Tanggal);
    begin
        with mTanggal do 
        begin
            if (dd >= 0) then write(dd div 10, dd mod 10) else write('__');
            write(':');
            if (mm >= 0) then write(mm div 10, mm mod 10) else write('__');
            write(':');
            if (yy >= 0) then write(yy div 1000, (yy mod 1000) div 100, (yy mod 100) div 10, yy mod 10) else write('____');
        end;
    end;

    procedure print(mJadwal:Jadwal);
    begin
        with mJadwal do
        begin
            print(FlightNo); write(' | ');
            print(KotaAsal); write(' | ');
            print(KotaTujuan); write(' | ');
            print(RencanaTanggalBerangkat); write(' | ');
            print(RencanaJamBerangkat); write(' | ');
            print(RencanaTanggalKedatangan); write(' | ');
            print(RencanaJamKedatangan); write(' | ');
            print(ImplementasiTanggalBerangkat); write(' | ');
            print(ImplementasiJamBerangkat); write(' | ');
            print(ImplementasiTanggalKedatangan); write(' | ');
            print(ImplementasiJamKedatangan); writeln;
        end;
    end;