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
  static final long mod = (int) 1e9 + 13;
  static final long prime = 13331;
  
  long[] power = new long[2005];
  long[] hash = new long[2005];
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    power[0] = 1;
    for(int i = 1; i < 2005; i++) {
      power[i] = power[i - 1] * prime;
      power[i] %= mod;
    }
    
    String s = in.next();
    String tab = in.next();
    int k = in.nextInt();
    
    hash[0] = s.charAt(0) - 'a' + 1;
    for(int i = 1; i < s.length(); i++) {
      hash[i] = hash[i - 1] * prime + s.charAt(i) - 'a' + 1;
      hash[i] %= mod;
    }
    ArrayList<Long> set = new ArrayList<Long>();
    for(int i = 0; i < s.length(); i++) {
      int now = 0;
      for(int j = i; j < s.length(); j++) {
        if(tab.charAt(s.charAt(j) - 'a') == '0') {
          now++;
        }
        if(now > k) break;
        long val = hash[j] - (i > 0? hash[i - 1] * power[j - i + 1] : 0);
        val %= mod; if(val < 0) val += mod;
        set.add(val);
        //out.println(i + " " + j);
      }
    }
    Collections.sort(set);
    int ans = (set.isEmpty()? 0 : 1);
    for(int i = 1; i < set.size(); i++) {
      if(set.get(i) - set.get(i - 1) == 0) {
        continue;
      }
      ans++;
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