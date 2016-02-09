import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class party {
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
  int[] par;
  List[] edge;
  int ans = 0;
  
  void dfs(int now, int c) {
    ans = Math.max(ans, c);
    for(int i = 0; i < edge[now].size(); i++) {
      dfs(edge[now].get(i), c + 1);
    }
  }
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    edge = new List[n + 1];
    for(int i = 1; i <= n; i++) {
      edge[i] = new ArrayList<Integer>();
    }
    par = new int[n];
    for(int i = 1; i <= n; i++) {
      par[i] = in.nextInt();
      if(par[i] != -1) {
        edge[par[i]].add(i);
      }
    }
    for(int i = 1; i <= n; i++) {
      if(par[i] == -1) {
        dfs(i, 1);
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