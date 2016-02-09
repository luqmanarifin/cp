import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class catalan {
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
	static final int N = (int) 1e4 + 5;
	
	BigInteger[] fact = new BigInteger[N];
	BigInteger[] cat = new BigInteger[N];
	
	private BigInteger findFact(int n) {
		if(fact[n].compareTo(BigInteger.valueOf(0)) != 0) return fact[n];
		if(n == 0) return fact[0] = BigInteger.valueOf(1);
		BigInteger temp = findFact(n - 1);
		temp = temp.multiply(BigInteger.valueOf(n));
		return fact[n] = temp;
	}
	
	private BigInteger findCat(int n) {
		if(cat[n].compareTo(BigInteger.valueOf(0)) != 0) return cat[n];
		BigInteger ret = findFact(2*n);
		ret = ret.divide(findFact(n));
		ret = ret.divide(findFact(n));
		ret = ret.divide(BigInteger.valueOf(n + 1));
		return cat[n] = ret;
	}
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		int n = in.nextInt();
		for(int i = 0; i < N; i++) {
			fact[i] = BigInteger.valueOf(0);
			cat[i] = BigInteger.valueOf(0);
		}
		/*
		BigInteger ans = BigInteger.valueOf(0);
		for(int k = 0; k <= n; k++) {
			BigInteger temp = findCat(k);
			temp = temp.multiply(findCat(n - k));
			ans = ans.add(temp);
		} */
		out.println(findCat(n + 1));
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