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
  int[][] a = new int[5555][5555];
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    int m = in.nextInt();
    int q = in.nextInt();
    int[] max = new int[555];
    for(int i = 1; i <= n; i++) {
      int now = 0;
      for(int j = 1; j <= m; j++) {
        a[i][j] = in.nextInt();
        if(a[i][j] == 1) now++;
        else now = 0;
        max[i] = Math.max(max[i], now);
      }
    }
    for(int qq = 0; qq < q; qq++) {
      int l = in.nextInt();
      int r = in.nextInt();
      a[l][r] ^= 1;
      int now = 0;
      max[l] = 0;
      for(int j = 1; j <= m; j++) {
        if(a[l][j] == 1) now++;
        else now = 0;
        max[l] = Math.max(max[l], now);
      }
      int ans = 0;
      for(int i = 1; i <= n; i++) {
        ans = Math.max(ans, max[i]);
      }
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