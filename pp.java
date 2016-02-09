import java.util.*;
import java.io.*;
import java.lang.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class point {
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
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		int[] x = new int[205];
		int[] y = new int[205];
		int n = in.nextInt();
		for(int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			boolean lower = false;
			boolean upper = false;
			boolean left = false;
			boolean right = false;
			for(int j = 0; j < n; j++) {
				if(x[i] == x[j] && y[i] < y[j])
					upper = true;
				if(x[i] == x[j] && y[i] > y[j])
					lower = true;
				if(x[i] > x[j] && y[i] == y[j])
					right = true;
				if(x[i] < x[j] && y[i] == y[j])
					left = true;
			}
			if(lower && upper && left && right) ans++;
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