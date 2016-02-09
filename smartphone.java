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
  static final int N = (int) (1e5 + 5);
  
  int[] at = new int[N];
  int[] a = new int[N];
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    // type the code here
    int n = in.nextInt();
    int m = in.nextInt();
    int k = in.nextInt();
    for(int i = 0; i < n; i++) {
      a[i] = in.nextInt();
      at[a[i]] = i;
    }
    long ans = 0;
    for(int tt = 0; tt < m; tt++) {
      int t = in.nextInt();
      ans += at[t] / k + 1;
      if(at[t] > 0) {
        int bef = a[at[t] - 1];
        a[at[t] - 1] = t;
        a[at[t]] = bef;
        at[t]--;
        at[bef]++;
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