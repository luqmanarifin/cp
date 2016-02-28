import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class rozdil {
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
    if(n == 1) {
      out.println(1);
      return;
    }
    int[] a = new int[n];
    int[] s = new int[n];
    for(int i = 0; i < n; i++) {
      a[i] = in.nextInt();
      s[i] = a[i];
    }
    Arrays.sort(s);
    if(s[0] == s[1]) {
      out.println("Still Rozdil");
      return;
    }
    for(int i = 0; i < n; i++) {
      if(a[i] == s[0]) {
        out.println(i + 1);
        return;
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