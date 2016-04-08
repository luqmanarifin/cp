import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class m {
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
  BigInteger lcm(BigInteger a, BigInteger b) {
    BigInteger temp = a.multiply(b);
    return temp.divide(a.gcd(b));
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    BigInteger a[] = new BigInteger[n];
    BigInteger b[] = new BigInteger[n];
    BigInteger kpk = BigInteger.valueOf(1);
    for(int i = 0; i < n; i++) {
      int u = in.nextInt();
      int v = in.nextInt();
      a[i] = BigInteger.valueOf(u);
      b[i] = BigInteger.valueOf(v);
      kpk = lcm(kpk, b[i]);
    }
    BigInteger atas = BigInteger.valueOf(1);
    for(int i = 0; i < n; i++) {
      a[i] = a[i].multiply(kpk.divide(b[i]));
      atas = lcm(atas, a[i]);
    }
    BigInteger f = atas.gcd(kpk);
    out.println(atas.divide(f) + " " + kpk.divide(f));
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