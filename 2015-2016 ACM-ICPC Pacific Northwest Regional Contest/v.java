import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class v {
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
  final int N = 1005;
  
  int[] a = new int[N];
  int[] b = new int[N];
  int[] r = new int[N];
  int[] d = new int[N];
  BigInteger[] num = new BigInteger[N];
  BigInteger[] den = new BigInteger[N];
  boolean[] done = new boolean[N];
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    for(int i = 0; i < n; i++) {
      a[i] = in.nextInt();
      b[i] = in.nextInt();
      r[i] = in.nextInt();
    }
    done[0] = true;
    num[0] = BigInteger.valueOf(1);
    den[0] = BigInteger.valueOf(1);
    d[0] = 1;
    int[] q = new int[N];
    int beg = 0, e = 0;
    q[e++] = 0;
    while(beg < e) {
      int now = q[beg++];
      for(int i = 0; i < n; i++) {
        if(i == now) continue;
        int delta = (a[i] - a[now])*(a[i] - a[now]) + (b[i] - b[now])*(b[i] - b[now]);
        int sum = (r[now] + r[i])*(r[now] + r[i]);
        if(delta == sum) {
          if(done[i] && d[i] == d[now]) {
            out.println("The input gear cannot move.");
            return;
          }
          if(!done[i]) {
            q[e++] = i;
            done[i] = true;
            num[i] = num[i].multiply(BigInteger.valueOf(r[now]));
            den[i] = den[i].multiply(BigInteger.valueOf(r[i]));
            BigInteger fpb = num[i].gcd(den[i]);
            num[i] = num[i].divide(fpb);
            den[i] = den[i].divide(fpb);
            d[i] = d[now] * -1;
          }
        }
      }
    }
    if(!done[n - 1]) {
      out.println("The input gear is not connected to the output gear.");
      return;
    }
    if(d[n - 1] == -1) {
      out.print("-");
    }
    out.println(num[n - 1] + ":" + den[n - 1]);
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