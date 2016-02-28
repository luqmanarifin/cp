import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class gremlins {
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
  int p;

  int __builtin_popcount(int mask) {
    int ret = 0;
    for(int i = 0; i < p; i++) {
      if((mask & (1 << i)) != 0) {
        ret++;
      }
    }
    return ret;
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int t = in.nextInt();
    while(t-- > 0) {
      long n = in.nextLong();
      p = in.nextInt();
      int[] a = new int[p];
      for(int i = 0; i < p; i++) {
        a[i] = in.nextInt();
      }
      long[] divi = new long[p];
      for(int i = 0; i < p; i++) {
        divi[i] = n / a[i] + 1;
      }
      BigInteger ans = BigInteger.valueOf(0);
      for(int mask = 1; mask < (1 << p); mask++) {
        long now = 1;
        boolean over = false;
        for(int i = 0; i < p; i++) {
          if((mask & (1 << i)) != 0) {
            boolean cuk = false;
            if(now > divi[i]) {
              over = true;
              break;
            }
            now *= a[i];
          }
        }
        if(now > n || n < 0 || over) continue;
        int cnt = __builtin_popcount(mask);
        BigInteger add = BigInteger.valueOf(cnt % 2 == 1? n / now : -n / now);
        add = add.multiply(BigInteger.valueOf(1 << (cnt - 1)));
        ans = ans.add(add);
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