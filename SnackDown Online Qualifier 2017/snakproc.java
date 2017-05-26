import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

class Main {
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
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int t = in.nextInt();
    while (t-- > 0) {
      int n = in.nextInt();
      String s = in.next();
      boolean valid = true;
      int now = 0;
      for (int i = 0; i < n; i++) {
        if (s.charAt(i) == 'H') {
          now++;
        } else if (s.charAt(i) == 'T') {
          now--;
        }
        if (now < 0) valid = false;
        if (now > 1) valid = false;
      }
      if (now != 0) valid = false;
      System.out.println(valid? "Valid" : "Invalid");
    }
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
