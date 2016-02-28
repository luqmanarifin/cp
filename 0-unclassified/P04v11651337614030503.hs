-- NIM/Nama  : 16513376 / Luqman A. Siswanto
-- Nama file : P04v11651337614030503.hs
-- Topik     : pisahDua
-- Tanggal   : 5 Maret 2014
-- Deskripsi : Membuat fungsi pisahDua sesuai deskripsi soal

-- Definisi dan Spesifikasi
ambilDepan :: ([Int], Int) -> [Int]

-- Realisasi
ambilDepan (l,n) =
	if (n <= 0 || null l) then []
		-- basis
	else [head l] ++  ambilDepan(tail l, n-1)
		-- rekurens

-- Definisi dan Spesifikasi
ambilBuntut :: ([Int], Int) -> [Int]

-- Realisasi
ambilBuntut (l,n) =
	if (n <= 0 || null l) then []
		-- basis
	else ambilBuntut(init l, n-1) ++ [last l]
		-- rekurens

-- Definisi dan Spesifikasi
pisahDua :: ([Int], Int) -> ([Int],[Int])

-- Realisasi
pisahDua (l,n) = (ambilDepan(l,n), ambilBuntut(l,length l - n))
