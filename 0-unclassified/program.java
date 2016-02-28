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
  static final long offset = (long) 1e16;
  static final int N = (int) 2e5 + 5;
  
  long[][] dp = new long[N][2];
  boolean[][] done = new boolean[N][2];
  int[] a = new int[N];
  int n;
  
  long dfs(int at, int t) {
    if(at > n || at <= 0) {
      return 0;
    }
    if(dp[at][t] != 0) return dp[at][t];
    if(done[at][t]) return dp[at][t] = -1;
    done[at][t] = true;
    
    long rec = (t == 1? dfs(at - a[at], t ^ 1) : dfs(at + a[at], t ^ 1));
    if(rec == -1) return dp[at][t] = -1;
    return dp[at][t] = rec + a[at];
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    n = in.nextInt();
    for(int i = 2; i <= n; i++) {
      a[i] = in.nextInt();
    }
    dp[1][0] = -1;
    dp[1][1] = offset;
    for(int i = 1; i < n; i++) {
      long ans = dfs(1 + i, 1);
      if(ans == -1) out.println(-1);
      else if(ans >= offset) out.println(ans - offset + 2 * i);
      else out.println(ans + i);
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