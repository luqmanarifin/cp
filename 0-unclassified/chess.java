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
  static final int MOD = (int) (1e9 + 7);
  
  private int con(char c) {
    switch(c) {
      case 'q' : return 9;
      case 'r' : return 5;
      case 'b' : return 3;
      case 'n' : return 3;
      case 'p' : return 1;
    }
    return 0;
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    // type the code here
    int a = 0, b = 0;
    for(int i = 0; i < 8; i++) {
      String s = in.next();
      for(int j = 0; j < 8; j++) {
        if(s.charAt(j) == '.') continue;
        if('A' <= s.charAt(j) && s.charAt(j) <= 'Z') {
          a += con((char) (s.charAt(j) - 'A' + 'a'));
        } else {
          b += con(s.charAt(j));
        }
      }
    }
    if(a > b) {
      out.println("White");
    } else if(a < b) {
      out.println("Black");
    } else {
      out.println("Draw");
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