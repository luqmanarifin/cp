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
  static final int inf = (int) 1e9;
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    int m = in.nextInt();
    int[] a = new int[5555];
    for(int i = 1; i <= n; i++) {
      a[i] = in.nextInt();
      double x = in.nextDouble();
    }
    int[][] dp = new int[5005][5005];
    for(int i = 0; i < 5005; i++) {
      Arrays.fill(dp[i], -inf);
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
      int maxi = -inf;
      for(int j = 0; j <= m; j++) {
        dp[i][j] = dp[i - 1][j];
      }
      for(int j = 0; j <= a[i]; j++) {
        maxi = Math.max(maxi, dp[i - 1][j]);
      }
      dp[i][a[i]] = maxi + 1;
    }
    int ans = 0;
    for(int i = 0; i <= m; i++) {
      ans = Math.max(ans, dp[n][i]);
    }
    out.println(n - ans);
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