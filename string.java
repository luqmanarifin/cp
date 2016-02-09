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
  static final int N = (int) (2e5 + 5);
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    // type the code here
    StringBuilder s = new StringBuilder(in.next());
    int m = in.nextInt();
    boolean[] rev = new boolean[N];
    Arrays.fill(rev, false);
    for(int i = 0; i < m; i++) {
      int a = in.nextInt();
      a--;
      rev[a] = !rev[a];
    }
    int n = s.length();
    for(int i = 0; i < n / 2; i++) {
      if(i > 0 && rev[i - 1]) {
        rev[i] = !rev[i];
      }
      if(rev[i]) {
        char temp = s.charAt(i);
        s.setCharAt(i, s.charAt(n - i - 1));
        s.setCharAt(n - i - 1, temp);
      }
    }
    out.println(s);
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