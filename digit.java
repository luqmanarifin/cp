import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class digit {
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
	boolean[] done = new boolean[40];
	int[] ans = new int[40];
	int base;
	
	private boolean find(BigInteger now, int pos) {
		if(pos == base) return true;
		BigInteger cur = now.multiply(BigInteger.valueOf(base));
		for(int i = 1; i < base; i++) {
			if(done[i]) continue;
			BigInteger nex = cur.add(BigInteger.valueOf(i));
			BigInteger rem = nex.mod(BigInteger.valueOf(pos));
			BigInteger nol = BigInteger.valueOf(0);
			if(rem.compareTo(nol) == 0) {
				done[i] = true;
				ans[pos] = i;
				if(find(nex, pos + 1)) return true;
				done[i] = false;
			}
		}
		return false;
	}
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		base = in.nextInt();
		if(find(BigInteger.valueOf(0), 1)) {
			for(int i = 1; i < base; i++) {
				if(ans[i] < 10) out.print(ans[i]);
				else out.print((char) (ans[i] - 10 + 'A'));
			}
		} else out.print("No");
		out.println();
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