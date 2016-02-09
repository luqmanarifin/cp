#ifndef POINT_H
#define POINT_H

#include <stdbool.h>

typedef struct {
	float X, Y;
} POINT;

{ *** Definisi ABSTRACT DATA TYPE POINT *** } 
type POINT : < X : real, { absis } 
 Y : real { ordinat } > 
 
{ *** DEFINISI PROTOTIPE PRIMITIF *** } 
{ *** Konstruktor membentuk POINT *** } 
function MakePOINT (X : real; Y : real) → POINT 
{ Membentuk sebuah POINT dari komponen-komponennya } 
{ *** Operasi terhadap komponen : selektor Get dan Set *** } 
{ *** Selektor POINT *** } 
function GetAbsis (P : POINT) → real
{ Mengirimkan komponen absis dari P } 
function GetOrdinat (P:POINT) → real
{ Mengirimkan komponen ordinat dari P POINT } 
{ *** Set nilai komponen *** } 
procedure SetAbsis (input/output P : POINT, input newX : real) 
{ Mengubah nilai komponen absis dari P } 
procedure SetOrdinat (input/output P:POINT, input newY : real) 
{ Mengubah nilai komponen ordinat dari P } 
{ *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS *** } 
procedure BacaPOINT (output P : POINT) 
{ Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan 
dari nilai absis dan ordinat tersebut } 
{ I.S. Sembarang } 
{ F.S. P terdefinisi } 
procedure TulisPOINT (input P : POINT) 
{ Nilai P ditulis ke layar dengan format "(X,Y)" } 
{ I.S. P terdefinisi } 
{ F.S. P tertulis di layer dengan format "(X,Y)" } 
{ *** Kelompok operasi relasional terhadap POINT *** } 
function EQ (P1, P2 : POINT) → boolean
{ Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama } 
function NEQ (P1, P2 : POINT) → boolean
{ Mengirimkan true jika P1 tidak sama dengan P2 } 
{ *** Kelompok menentukan di mana P berada *** } 
function IsOrigin (P : POINT) → boolean
{ Menghasilkan true jika P adalah titik origin } 
function IsOnSbX (P : POINT) → boolean
{ Menghasilkan true jika P terletak Pada sumbu X } 
function IsOnSbY (P : POINT) → boolean
{ Menghasilkan true jika P terletak pada sumbu Y } 
function Kuadran (P : POINT) → integer
{ Menghasilkan kuadran dari P: 1, 2, 3, atau 4 } 
{ Prekondisi : P bukan Titik Origin, } 
{ dan P tidak terletak di salah satu sumbu } 
{ *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** } 
function NextX (P : POINT) → POINT 
{ Mengirim salinan P dengan absis ditambah satu } 
function NextY (P : POINT) → POINT 
{ Mengirim salinan P dengan ordinat ditambah satu } 
function PlusDelta (P : POINT; deltaX, deltaY : real) → POINT 
{ Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah 
Ordinat(P) + deltaY } 
function MirrorOf (P : POINT; SbX : boolean) → POINT 
{ Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu } 
{ Jika SbX bernilai true, maka dicerminkan terhadap sumbu X } 
{ Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y } 
function Jarak0 (P : POINT) → real
{ Menghitung jarak P ke (0,0) } 
function Panjang (P1, P2 : POINT) → real
{ Menghitung panjang garis yang dibentuk P1 dan P2 } 
{ Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. 
Tuliskan spec fungsi yang lebih tepat. } 
procedure Geser (input/output P : POINT, input deltaX, deltaY : real) 
{ I.S. P terdefinisi } 
{ F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY } 
procedure GeserKeSbX (input/output P : POINT) 
{ I.S. P terdefinisi } 
{ F.S. P berada pada sumbu X dengan absis sama dengan absis semula. } 
{ Proses : P digeser ke sumbu X. } 
{ Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) } 
procedure GeserKeSbY (input/output P : POINT) 
{ I.S. P terdefinisi} 
{ F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. } 
{ Proses : P digeser ke sumbu Y. } 
{ Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) } 
procedure Mirror (input/output P : POINT, input SbX : boolean) 
{ I.S. P terdefinisi } 
{ F.S. P dicerminkan tergantung nilai SbX atau SbY } 
{ Jika SbX true maka dicerminkan terhadap sumbu X } 
{ Jika SbX false maka dicerminkan terhadap sumbu Y } 
procedure Putar (input/output P : POINT, input Sudut : real) 
{ I.S. P terdefinisi } 
{ F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) } 