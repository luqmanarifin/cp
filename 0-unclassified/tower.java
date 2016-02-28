import java.util.*;
import java.io.*;
import java.lang.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class tower {
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
	
	public long sum(long n) {
		return n * (n + 1) / 2;
	}
	
	int[][] dp;
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		int r = in.nextInt();
		int g = in.nextInt();
		int tot = r + g;
		int lef = 1, rig = 1000;
		while(lef < rig) {
			int mid = (lef + rig + 1) >> 1;
			if((long) tot < sum(mid)) rig = mid - 1;
			else lef = mid;
		}
		int m = Math.max(r, g);
		r = Math.min(r, g);
		
		dp = new int[2][r + 2];
		dp[0][0] = 1;
		for(int i = 1; i <= lef; i++) {
			int now = i & 1;
			int prev = now ^ 1;
			int last = Math.min((int) sum(i), r);
			for(int j = 0; j <= last; j++) {
				dp[now][j] = dp[prev][j];
				if(j - i >= 0) dp[now][j] += dp[prev][j - i];
				if(dp[now][j] >= MOD)
					dp[now][j] -= MOD;
			}
		}
		int ans = 0;
		int pake = (int) sum(lef);
		lef = lef & 1;
		for(int j = Math.max(pake - m, 0); j <= r; j++) {
			ans += dp[lef][j];
			if(ans >= MOD) ans -= MOD;
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