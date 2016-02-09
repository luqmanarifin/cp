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
    int num = in.nextInt();
    for(int i = 0; i < num; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }
}

class Task {
  static final int MOD = (int) (1e9 + 7);
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    // type the code here
    int n = in.nextInt();
    int w = in.nextInt();
    int[] a = new int[n];
    for(int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        int buy = w / a[i];
        ans = Math.max(ans, (a[j] - a[i]) * buy);
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