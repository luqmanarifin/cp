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
  static final int inf = (int) 1e9;
  
  int[][] source = new int[505][505];
  int[][] dist = new int[505][505];
  int[] urut = new int[505];
  long[] ans = new long[505];

  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        source[i][j] = in.nextInt();
        dist[i][j] = inf;
      }
      dist[i][i] = 0;
    }
    for(int i = 0; i < n; i++) {
      urut[i] = in.nextInt();
    }
    ArrayList<Integer> set = new ArrayList<Integer>();
    for(int u = n - 1; u >= 0; u--) {
      long cur = 0;
      for(Integer it : set) {
        dist[urut[u]][it] = Math.min(dist[urut[u]][it], source[urut[u]][it]);
        dist[it][urut[u]] = Math.min(dist[it][urut[u]], source[it][urut[u]]);
      }
      for(int mid = 1; mid <= n; mid++) {
        for(int i = 1; i <= n; i++) {
          dist[i][urut[u]] = Math.min(dist[i][urut[u]], dist[i][mid] + dist[mid][urut[u]]);
          dist[urut[u]][i] = Math.min(dist[urut[u]][i], dist[urut[u]][mid] + dist[mid][i]);
        }
      }
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          dist[i][j] = Math.min(dist[i][j], dist[i][urut[u]] + dist[urut[u]][j]);
        }
      }
      set.add(urut[u]);
      for(Integer i : set) {
        for(Integer j : set) {
          cur += dist[i][j];
        }
      }
      ans[u] = cur;
    }
    for(int i = 0; i < n; i++) {
      out.print(ans[i] + " ");
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