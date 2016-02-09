import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * 
 * Actual solution is at the top
 */

class e {
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
  static final int N = (int) 3e5 + 5;
  
  int[] cnt = new int[N];

  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    for(int i = 0; i < n; i++) {
      int l = in.nextInt();
      int r = in.nextInt();
      cnt[l]++;
      cnt[r + 1]--;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
      if(i > 0) cnt[i] += cnt[i - 1];
      if(cnt[i] > i) {
        ans = i + 1;
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