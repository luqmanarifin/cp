import java.util.*;
import java.io.*;
import java.lang.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class wifi {
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
	
	double[][] dp = new double[15][25];
	String s, t;
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		s = in.next();
		t = in.next();
		int n = s.length(), i, j, ans = 0;
		for(i = 0; i < n; i++) {
			if(s.charAt(i) == '+') ans++;
			else ans--;
		}
		
		dp[0][10] = 1.0;
		for(i = 1; i <= n; i++) {
			for(j = 0; j < 25; j++) {
				if(t.charAt(i - 1) == '+') {
					if(j > 0) dp[i][j] += dp[i - 1][j - 1];
				} else if(t.charAt(i - 1) == '-') {
					if(j + 1 < 25) dp[i][j] += dp[i - 1][j + 1];
				} else {
					if(j > 0) dp[i][j] += 0.5 * dp[i - 1][j - 1];
					if(j + 1 < 25) dp[i][j] += 0.5 * dp[i - 1][j + 1];
				}
			}
		}
		out.println(String.format("%.18f", dp[n][ans + 10]));
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