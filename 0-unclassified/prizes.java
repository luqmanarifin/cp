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
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    int[] record = new int[55];
    for(int i = 0; i < n; i++) {
      record[i] = in.nextInt();
    }
    int[] prize = new int[5];
    for(int i = 0; i < 5; i++) {
      prize[i] = in.nextInt();
    }
    long[] ans = new long[5];
    
    long now = 0;
    for(int i = 0; i < n; i++) {
      now += record[i];
      for(int j = 4; j >= 0; j--) {
        long buy = now / prize[j];
        ans[j] += buy;
        now -= buy * prize[j];
      }
    }
    for(int i = 0; i < 5; i++) {
      out.print(ans[i] + " ");
    }
    out.println();
    out.println(now);
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