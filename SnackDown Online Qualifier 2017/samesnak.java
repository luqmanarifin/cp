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
  class Loc {
    int x, y;
    Loc (int x, int y) {
      this.x = x;
      this.y = y;
    }
    boolean equal(Loc a) {
      return this.x == a.x && this.y == a.y;
    }
  }
  
  boolean intersect(int a, int b, int c, int d) {
    int l = Math.min(a, b);
    int r = Math.max(a, b);
    int p = Math.min(c, d);
    int q = Math.max(c, d);
    if (p < l) {
      int tmp = p;
      p = l;
      l = tmp;
      
      tmp = q;
      q = r;
      r = tmp;
    }
    return p <= r;
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int t = in.nextInt();
    while (t-- > 0) {
      int a = in.nextInt();
      int b = in.nextInt();
      int c = in.nextInt();
      int d = in.nextInt();
      int e = in.nextInt();
      int f = in.nextInt();
      int g = in.nextInt();
      int h = in.nextInt();
      if (a == c && c == e && e == g) {
        if (intersect(b, d, f, h)) {
          System.out.println("yes");
        } else {
          System.out.println("no");
        }
        continue;
      }
      if (b == d && d == f && f == h) {
        if (intersect(a, c, e, g)) {
          System.out.println("yes");
        } else {
          System.out.println("no");
        }
        continue;
      }
      Loc A = new Loc(a, b);
      Loc B = new Loc(c, d);
      Loc C = new Loc(e, f);
      Loc D = new Loc(g, h);
      if (A.equal(C) || A.equal(D) || B.equal(C) || B.equal(D)) {
        System.out.println("yes");
      } else {
        System.out.println("no");
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
