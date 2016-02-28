import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class bob {
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
		int[] sell = new int[5005];
		int[] lastWin = new int[5005];
		int[] it = new int[5005];
		boolean[] done = new boolean[5005];
		String[] op = new String[5005];
		BigInteger[] dua = new BigInteger[5005];
		Arrays.fill(sell, 0);
		Arrays.fill(lastWin, 0);
		Arrays.fill(done, false);
		
		dua[0] = BigInteger.valueOf(1);
		int i, j;
		for(i = 1; i <= 2500; ++i)
			dua[i] = dua[i-1].multiply(BigInteger.valueOf(2));
			
		int n = in.nextInt();
		for(i = 1; i <= n; ++i) {
			op[i] = in.next();
			it[i] = in.nextInt();
			if(op[i].equals("sell"))
				sell[it[i]] = i;
		}
		for(i = 1; i <= n; ++i) {
			if(op[i].equals("win"))
				if(i < sell[it[i]])
					lastWin[it[i]] = i;
		}
		
		BigInteger ans = BigInteger.valueOf(0);
		for(i = 2000; i >= 0; i--) {
			if(sell[i] > 0 && lastWin[i] > 0) {
				boolean ada = false;
				for(j = lastWin[i]; j <= sell[i]; j++)
					if(done[j])
						ada = true;
						
				if(!ada) {
					ans = ans.add(dua[i]);
					for(j = lastWin[i]; j <= sell[i]; j++)
						done[j] = true;
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
}