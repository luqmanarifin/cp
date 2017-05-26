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
  int lower_bound(int[] a, int n, int val) {
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (a[mid] < val) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int t = in.nextInt();
    while (t-- > 0) {
      int n = in.nextInt();
      int q = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      Arrays.sort(a);
      long[] s = new long[n + 1];
      for (int i = 0; i < n + 1; i++) {
        if (i > 0) s[i] = s[i - 1];
        if (i < n) s[i] += a[i];
        //System.out.print(s[i] + " ");
      }
      //System.out.println();
      while (q-- > 0) {
        int v = in.nextInt();
        int p = lower_bound(a, n, v);
        int l = 0, r = p;
        while (l < r) {
          int mid = (l + r) / 2;
          int ada = mid;
          long need = 1L * (p - mid) * v - (s[p - 1] - (mid > 0? s[mid - 1] : 0));
          //System.out.println(mid + " " + ada + " " + need);
          if (ada >= need) {
            r = mid;
          } else {
            l = mid + 1;
          }
        }
        System.out.println(n - l);
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
