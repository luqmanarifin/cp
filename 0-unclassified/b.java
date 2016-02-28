import java.io.*; 
import java.lang.*; 
import java.util.*; 
import java.math.*;

public class b {
  private BigInteger[] a;
  private BigInteger w, x, y;

  public static void main(String[] args) throws Exception {
    b solver = new b();
  }

  b() throws Exception {
    InputReader in = new InputReader(System.in);

    a = new BigInteger[3];
    for (int i = 0; i < 3; ++i) {
      a[i] = new BigInteger(in.next());
    }
    Arrays.sort(a);

    w = new BigInteger("0");
    w = w.add(a[0]);
    w = w.add(a[0]);

    x = new BigInteger("0");
    x = x.add(a[0]);
    x = x.add(a[1]);

    y = new BigInteger("0");
    y = y.add(a[1]);
    y = y.add(a[1]);

    if (w.equals(a[2]) || x.equals(a[2]) || y.equals(a[2]))
      System.out.println("YES");
    else
      System.out.println("NO");
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