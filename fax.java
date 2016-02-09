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
  String s;
  
  boolean palin(int l, int r) {
    int len = r - l + 1;
    for(int i = 0; i < len; i++) {
      if(s.charAt(l + i) != s.charAt(r - i)) {
        return false;
      }
    }
    return true;
  }

  public void solve(int testNumber, InputReader in, PrintWriter out) {
    s = in.next();
    int k = in.nextInt();
    int n = s.length();
    if(n % k != 0) {
      out.println("NO");
      return;
    }
    for(int i = 0; i < n; i += n / k) {
      if(!palin(i, i + n / k - 1)) {
        out.println("NO");
        return;
      }
    }
    out.println("YES");
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