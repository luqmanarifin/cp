import java.io.*; 
import java.lang.*; 
import java.util.*; 
import java.math.*;

public class b {
  private char[] s;

  public static void main(String[] args) throws Exception {
    b solver = new b();
  }

  b() throws Exception {
    InputReader in = new InputReader(System.in);

    s = in.next().toCharArray();

    int one = 0, zer = 0;
    for (char c : s) {
      if (c == '0') zer++; else one++;
    }

    System.out.println(Math.min(zer, one));
  }
}

class InputReader {
  private BufferedReader reader;
  private StringTokenizer tokenizer;

  InputReader(InputStream input) {
    reader = new BufferedReader(
            new InputStreamReader(input), 
            32768);
    tokenizer = null;
  }

  public String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  public int nextInt() {
    return Integer.parseInt(next());
  }
  
  public long nextLong() {
    return Long.parseLong(next());
  }
}

class DisjointSet {
  private int[] set;
  private int[] rank;
  private int distinct;

  public DisjointSet(int n) {
    set = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i) set[i] = i;
    Arrays.fill(rank, 0);
    distinct = n;
  }

  public int find(int n) {
    if (set[n] != n) set[n] = find(set[n]);
    return set[n];
  }

  public void join(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (rank[x] < rank[y]) x ^= y ^= x ^= y;
    set[y] = x;
    rank[x] += rank[y];
    distinct--;
  }

  public int setNumber() { return distinct; }
}

class Pair<K extends Comparable<K>, V extends Comparable<V>> 
implements Comparable<Pair<K,V>> {
  public K first;
  public V second;

  public Pair(K first, V second) {
    this.first = first;
    this.second = second;
  }

  public Pair(Pair<K,V> rhs) {
    first = rhs.first;
    second = rhs.second;
  }

  public boolean equals(Pair<K,V> rhs) { return first.equals(rhs.first) && second.equals(rhs.second); }

  public String toString() {
    return "(" + first.toString() + "," + second.toString() + ")";
  }

  public int compareTo(Pair<K,V> rhs) {
    int res = first.compareTo(rhs.first);
    if (res != 0) return res;
    else return second.compareTo(rhs.second);
  }
}