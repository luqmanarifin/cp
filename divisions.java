import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
 
public class divisions {
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
  static final int N = (int) 1e6 + 1;

  public void solve(int testNumber, InputReader in, PrintWriter out) {
    BitSet is = new BitSet();
    long n = in.nextLong();
    long ans = 1;
    for(int i = 2; i < N; i++) {
      if(n % i == 0) {
        int c = 0;
        while(n % i == 0) {
          c++;
          n /= i;
        }
        ans *= c + 1;
      }
    }
    if(n > 1) {
      if(BigInteger.valueOf(n).isProbablePrime(20)) {
        ans *= 2;
      } else {
        long l = 0, r = (long) Math.sqrt(n) + 5;
        while(l < r) {
          long mid = (l + r + 1) >> 1;
          if(mid * mid <= n) {
            l = mid;
          } else {
            r = mid - 1;
          }
        }
        if(l * l == n) {
          ans *= 3;
        } else {
          ans *= 4;
        }
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