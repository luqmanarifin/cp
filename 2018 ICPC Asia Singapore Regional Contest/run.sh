rm $1
clear
g++ -O2 -o $1 $1.cpp -std=c++11 -DTESTING
time ./$1 < $1.in
