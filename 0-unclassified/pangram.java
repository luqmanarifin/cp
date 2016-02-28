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
    boolean[] ok = new boolean[26];
    int n = in.nextInt();
    String s = in.next();
    for(int i = 0; i < n; i++) {
      char c = s.charAt(i);
      if('a' <= c && c <= 'z') {
        ok[c - 'a'] = true;
      } else {
        ok[c - 'A'] = true;
      }
    }
    for(int i = 0; i < 26; i++) {
      if(!ok[i]) {
        out.println("NO");
        return;
      }
    }
    out.println("YES");
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