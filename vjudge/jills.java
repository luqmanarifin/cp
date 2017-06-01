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
  final int inf = (int) 1e9;
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int t = in.nextInt();
    for (int tt = 1; tt <= t; tt++) {
      int n = in.nextInt();
      int[] a = new int[n + 5];
      for (int i = 1; i < n; i++) {
        a[i] = in.nextInt();
      }
      int best = -inf, len = -1, st = -1;
      int cur = -inf, p = -1, q = -1;
      for (int i = 1; i < n; i++) {
        if (a[i] > cur + a[i]) {
          cur = a[i];
          p = i;
          q = i + 1;
        } else {
          cur += a[i];
          q++;
        }
        if (cur > best) {
          best = cur;
          len = q - p;
          st = p;
        } else if (cur == best) {
          if (q - p > len) {
            len = q - p;
            st = p;
          }
        }
      }
      if (best < 0) {
        System.out.format("Route %d has no nice parts\n", tt);
      } else {
        System.out.format("The nicest part of route %d is between stops %d and %d\n", tt, st, st + len);
      }
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
