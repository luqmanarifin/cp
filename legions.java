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
  static final int mod = (int) 1e8;
  
  // pos - status - footmen
  long[][][] dp = new long[205][2][105];
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int[] n = new int[2];
    int[] lim = new int[2];
    n[0] = in.nextInt();
    n[1] = in.nextInt();
    lim[0] = in.nextInt();
    lim[1] = in.nextInt();
    
    dp[0][0][0] = dp[0][1][0] = 1;
    int tot = n[0] + n[1];
    for(int i = 1; i <= tot; i++) {
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k <= n[0]; k++) {
          int will = (j == 0? k: i - k);
          int to = Math.min(will, lim[j]);
          for(int b = 1; b <= to && i - b >= 0; b++) {
            dp[i][j][k] += dp[i - b][j ^ 1][k - (j == 0? b : 0)];
          }
          dp[i][j][k] %= mod;
          //out.println("ans " + i + " " + j + " " + k + " : " + dp[i][j][k]);
        }
      }
    }
    long ans = 0;
    for(int i = 0; i < 2; i++) {
      ans += dp[tot][i][n[0]];
    }
    out.println(ans % mod);
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