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
  static final int N = 1000000;
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    // type the code here
    int n = in.nextInt();
    boolean f = false;
    long temp = 0;
    long ans = 0;
    int[] cnt = new int[N + 5];
    int[] asli = new int[N + 5];
    Arrays.fill(cnt, 0);
    Arrays.fill(asli, 0);
    for(int i = 0; i < n; i++) {
      int a = in.nextInt();
      cnt[a]++;
      asli[a]++;
    }
    for(int i = N; i >= 2; i--) {
      cnt[i] += Math.min(asli[i + 1], cnt[i + 1]);
      if(f && cnt[i] >= 2) {
        cnt[i] -= 2;
        f = false;
        ans += temp * i;
      }
      while(cnt[i] >= 4) {
        ans += (long) i * i;
        cnt[i] -= 4;
      }
      if(cnt[i] >= 2) {
        cnt[i] -= 2;
        f = true;
        temp = i;
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