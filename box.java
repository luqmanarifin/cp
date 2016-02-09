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
    int x = in.nextInt();
    int y = in.nextInt();
    int z = in.nextInt();;
    int x1 = in.nextInt();;
    int y1 = in.nextInt();;
    int z1 = in.nextInt();
    int a = in.nextInt();;
    int b = in.nextInt();
    int c = in.nextInt();
    int d = in.nextInt();
    int e = in.nextInt();
    int f = in.nextInt();
    int ans = (y < 0? a : 0) + (y > y1? b : 0) + (z < 0? c : 0);
    ans += (z > z1? d : 0) + (x < 0? e : 0) + (x > x1? f : 0);
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