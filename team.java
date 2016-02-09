import java.util.*;
import java.io.*;
import java.lang.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class team {
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
	
	long sum(long n) {
		return n*(n + 1)/2;
	}
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		long n = in.nextLong();
		long m = in.nextLong();
		long maxi = sum(n - m);
		long rem = n % m;
		long div = n / m;
		long mini = sum(div) * rem + sum(div - 1) * (m - rem);
		out.println(mini + " " + maxi);
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