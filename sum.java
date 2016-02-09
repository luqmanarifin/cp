import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class sum {
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
	
	public BigInteger getSumFirstNumber(long n) {
		BigInteger temp = BigInteger.valueOf(n);
		temp = temp.multiply(BigInteger.valueOf(n + 1));
		temp = temp.divide(BigInteger.valueOf(2));
		return temp;
	}

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		long a = in.nextLong();
		long b = in.nextLong();
		BigInteger ans = getSumFirstNumber(a);
		ans = ans.multiply(BigInteger.valueOf(b));
		ans = ans.add(BigInteger.valueOf(a));

		BigInteger x = getSumFirstNumber(b - 1);
		ans = ans.multiply(x);
		out.println(ans.mod(BigInteger.valueOf(MOD)));
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