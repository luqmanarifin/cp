import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class sums {
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
	static final long MOD = (int) (1e9 + 7);
	BigInteger temp;
	
	public long get(long l, long r) {
		long num = r - l + 1;
		BigInteger ha = temp.valueOf(num);
		ha = ha.multiply(temp.valueOf(l + r));
		ha = ha.divide(temp.valueOf(2));
		ha = ha.mod(temp.valueOf(MOD));
		long ret = ha.longValue();
		return ret;
	}
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		long a = in.nextLong();
		long b = in.nextLong();
		long ans = 0;
		for(long i = 1; i <= a; i++) {
			ans += get(i*b + 1, (i + 1)*b - 1);
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
}