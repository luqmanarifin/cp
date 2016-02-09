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
  
  static final long prime = 31;
  static final long mod = (int) (1e9 + 9);
  static final int N = (int) (1e5 + 5);
  
  long[] ha = new long[N];
  long[] hb = new long[N];
  long[] power = new long[N];
  
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    power[0] = 1;
    for(int i = 1; i < N; i++) {
      power[i] = power[i - 1] * prime;
      power[i] %= mod;
    }
    
    String a = in.next();
    String b = in.next();
    for(int i = 0; i < a.length(); i++) {
      ha[i] = a.charAt(i) - 'a' + 1;
      if(i > 0) {
        ha[i] += ha[i - 1] * prime;
        ha[i] %= mod;
      }
    }
    for(int i = 0; i < b.length(); i++) {
      hb[i] = b.charAt(i) - 'a' + 1;
      if(i > 0) {
        hb[i] += hb[i - 1] * prime;
        hb[i] %= mod;
      }
    }
    int ans = 0;
    for(int i = 1; i <= Math.min(a.length(), b.length()); i++) {
      if(a.charAt(i - 1) != b.charAt(i - 1)) {
        break;
      }
      if(a.length() % i == 0 && b.length() % i == 0) {
        boolean asama = true;
        for(int j = 2 * i - 1; j < a.length(); j += i) {
          long at = ha[j] - ha[j - i] * power[i];
          at %= mod; if(at < 0) at += mod;
          if(at != ha[i - 1]) {
            asama = false;
            break;
          }
        }
        boolean bsama = true;
        for(int j = 2 * i - 1; j < b.length(); j += i) {
          long at = hb[j] - hb[j - i] * power[i];
          at %= mod; if(at < 0) at += mod;
          if(at != hb[i - 1]) {
            bsama = false;
            break;
          }
        }
        if(asama && bsama) {
          ans++;
        }
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