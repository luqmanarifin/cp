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
  
  int n, len;
  int[] s;
  
  long solve(long x) {
    long ret = 0;
    for (int i = 0; i < n; i++) {
      ret += Math.abs(x + 1L * len * i - s[i]);
    }
    return ret;
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int t = in.nextInt();
    while (t-- > 0) {
      n = in.nextInt();
      len = in.nextInt();
      int a = in.nextInt();
      int b = in.nextInt();
      s = new int[n];
      for (int i = 0; i < n; i++) {
        s[i] = in.nextInt();
      }
      Arrays.sort(s);
      
      int l = a;
      int r = b - n * len;
      while (r - l > 3) {
        int lf = l + (r - l) / 3;
        int rf = r - (r - l) / 3;
        if (solve(lf) < solve(rf)) {
          r = rf;
        } else {
          l = lf;
        }
      }
      //System.out.println(l + " " + r);
      long ans = (long) 1e18;
      for (int i = l; i <= r; i++) {
        ans = Math.min(ans, solve(i));
      }
      System.out.println(ans);
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
