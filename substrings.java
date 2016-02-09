import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * 
 * Actual solution is at the top
 */

public class e {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Task solver = new Task();
    solver.solve(1, in, out);
    out.close();
  }
}

class Task {
  static final int MOD = (int) (1e9 + 7);
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    // type the code here
    ArrayList<TreeMap<Long, Integer>> m = new ArrayList<TreeMap<Long, Integer>>();
    for(int i = 0; i < 26; i++) {
      m.add(new TreeMap<Long, Integer>());
    }
    int[] x = new int[26];
    for(int i = 0; i < 26; i++) {
      x[i] = in.nextInt();
    }
    String s = in.next();
    int n = s.length();
    long now = 0, ans = 0;
    for(int i = 0; i < n; i++) {
      int at = s.charAt(i) - 'a';
      int map = (m.get(at).get(now) == null? 0 : m.get(at).get(now));
      ans += map;
      now += x[at];
      int add = (m.get(at).get(now) == null? 0 : m.get(at).get(now));
      m.get(at).put(now, add + 1);
    }
    out.println(ans);
  }
}

class InputReader {
  public BufferedReader reader;
  public StringTokenizer tokenizer;

  public InputReader(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream), 32768);
    tokenizer = null;
  }

  public String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (IOException e) {
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
	
  public double nextDouble() {
    return Double.parseDouble(next());
  }
}