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
  static final int mod = (int) (1e9 + 7);
  static final int N = (int) (1e5 + 5);
  
  long[] dp = new long[N];
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    // type the code here
    Arrays.fill(dp, 0);
    int t = in.nextInt();
    int k = in.nextInt();
    dp[0] = 1;
    for(int i = 1; i < N; i++) {
      dp[i] = dp[i - 1];
      if(i - k >= 0) dp[i] += dp[i - k];
      if(dp[i] >= mod) dp[i] -= mod;
    }
    for(int i = 1; i < N; i++) {
      dp[i] += dp[i - 1];
      dp[i] %= mod;
    }
    for(int tt = 0; tt < t; tt++) {
      int a = in.nextInt();
      int b = in.nextInt();
      long ans = dp[b] - dp[a - 1];
      if(ans < 0) ans += mod;
      out.println(ans);
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