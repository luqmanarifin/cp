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
  static final int N = (int) 1e6 + 5;
  
  // menandakan apakah string dengan panjang tertentu ada di tengah
  boolean[] ada = new boolean[N];
  int[] a = new int[N];
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    String s = in.next();
    int n = s.length();
    for(int i = 1; i < n; i++) {
      int j = a[i - 1];
      while(j > 0 && s.charAt(i) != s.charAt(j)) {
        j = a[j - 1];
      }
      if(s.charAt(i) == s.charAt(j)) {
        a[i] = j + 1;
        if(i < n - 1) {
          ada[a[i]] = true;
        }
      }
    }
    
    int now = a[n - 1];
    while(!ada[now] && now > 0) {
      now = a[now - 1];
    }
    if(now > 0) {
      for(int i = 0; i < now; i++) {
        out.print(s.charAt(i));
      }
    } else {
      out.println("Just a legend");
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