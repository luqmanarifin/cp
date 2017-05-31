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
  int[] num;
  int[] a;
  int n;
  final int inf = (int) 1e9;
  
  void build(int p, int l, int r) {
    if (l == r) {
      num[p] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = Math.min(num[p+p], num[p+p+1]);
  }
  
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return inf;
    int mid = (l + r) / 2;
    return Math.min(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    a = new int[n];
    num = new int[n << 2];
    for (int i = 0; i < n; i++) a[i] = in.nextInt();
    build(1, 0, n - 1);
    int q = in.nextInt();
    while (q-- > 0) {
      int l = in.nextInt();
      int r = in.nextInt();
      System.out.println(find(1, 0, n - 1, l, r));
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
