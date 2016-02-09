import java.util.*;
import java.io.*;
import java.lang.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class lift {
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
	
	int[][] fen;
	int[][] dp;
	int n;
	
	private void add(int i, int l, int val) {
		for(; l <= n; l |= l + 1) {
			fen[i][l] += val;
			if(fen[i][l] >= MOD) fen[i][l] -= MOD;
		}
	}
	
	private int take(int i, int l, int r) {
		int temp = get(i, r) - get(i, l - 1);
		if(temp < 0) temp += MOD;
		return temp;
	}
	
	private int get(int i, int pos) {
		long temp = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			temp += fen[i][pos];
			if(temp >= MOD) temp -= MOD;
		}
		return (int) temp;
	}
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		n = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		int k = in.nextInt();
		fen = new int[2][n + 1];
		dp = new int[2][n + 1];
		add(0, a, 1);
		dp[0][a] = 1;
		for(int i = 1; i <= k; i++) {
			int now = i & 1;
			int pre = now ^ 1;
			for(int j = 0; j <= n; j++) {
				dp[now][j] = 0;
				fen[now][j] = 0;
			}
			for(int j = 1; j <= n; j++) {
				if(j == b) continue;
				int dis = (Math.abs(b - j) - 1)/2;
				int isi;
				if(j < b) {
					isi = take(pre, 1, j + dis);
				} else {
					isi = take(pre, j - dis, n);
				}
				isi -= dp[pre][j];
				if(isi < 0) isi += MOD;
				add(now, j, isi);
				dp[now][j] = isi;
			}
		}
		out.println(take(k & 1, 1, n));
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