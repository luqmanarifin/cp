import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class bigrace {
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
  long gcd(long a, long b) {
    return b != 0? gcd(b, a % b) : a;
  }
  
  long kpk(long a, long b) {
    return a / gcd(a, b) * b;
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    long t = in.nextLong();
    long w = in.nextLong();
    long b = in.nextLong();
    long a;
    BigInteger ret = BigInteger.valueOf(b / gcd(b, w));
    ret = ret.multiply(BigInteger.valueOf(w));
    if(ret.compareTo(BigInteger.valueOf(t)) == 1) {
      a = 0;
    } else {
      a = t / kpk(b, w);
    }
    long x = kpk(b, w) * a;
    long ans = a * Math.min(b, w) + Math.min(t - x + 1, Math.min(b, w)) - 1;
    long fpb = gcd(ans, t);
    ans /= fpb;
    t /= fpb;
    out.println(ans + "/" + t);
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