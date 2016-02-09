import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class trees {
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
    int n = in.nextInt();
    int[] a = new int[n];
    for(int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int ans = n;
    int now = 0;
    for(int i = 0; i < n; i++) {
      ans += a[i] - now;
      if(i + 1 < n) {
        int h = Math.min(a[i], a[i + 1]);
        ans += a[i] - h + 1;
        now = h;
      }
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