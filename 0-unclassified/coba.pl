parent(charles,william).
parent(charles,harry).
parent(phillips,charles).
parent(elizabeth,charles).
parent(victoria,elizabeth).
ancestor(X,Y) :- parent(X,Y).
ancestor(X,Y) :- ancestor(X,Z), !, parent(Z,Y).