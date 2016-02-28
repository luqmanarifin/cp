import Data.List

solve w
	| mod w 2 == 0 && w /= 2 = "YES"
	| otherwise = "NO"

main = interact $ solve.read