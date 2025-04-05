import kotlin.math.abs
import kotlin.math.max
import kotlin.math.sqrt
 
private fun readLn() = readLine()!! // string line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() } // list of ints
private fun readInt() = readLn().toInt() // single int
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
fun main() {
    var t = readInt()
    while (t > 0) {
        t--
        val n = readInt()
        println(n - 1)
    }
}
