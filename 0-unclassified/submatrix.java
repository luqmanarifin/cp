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
  
  String[] s = new String[5555];
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    int m = in.nextInt();
    for(int i = 0; i < n; i++) {
      s[i] = in.next();
    }
    
    int[][] a = new int[n][m];
    for(int i = 0; i < n; i++) {
      int now = 0;
      for(int j = m - 1; j >= 0; j--) {
        if(s[i].charAt(j) == '1') now++;
        else now = 0;
        a[i][j] = now;
      }
    }
    int ans = 0;
    for(int j = 0; j < m; j++) {
      ArrayList<Integer> top = new ArrayList<Integer>();
      for(int i = 0; i < n; i++) {
        top.add(a[i][j]);
      }
      Collections.sort(top);
      Collections.reverse(top);
      for(int i = 0; i < n; i++) {
        ans = Math.max(ans, (i + 1) * top.get(i));
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