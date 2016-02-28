import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.lang.*;

public class program3 {
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
	private static final long mod = 1000000007;
	private static final int N = 1005;
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.nextInt(), m = in.nextInt(), i, j;
		int [][]asal = new int[N][N];
		int [][]a = new int[N][N];
		int [][]b = new int[N][N];
		int [][]c = new int[N][N];
		int [][]d = new int[N][N];
		long ans = 0;
		 
		for(i = 0; i < n; ++i)
			for(j = 0; j < m; ++j)
			asal[i][j] = in.nextInt();
		 
		Arrays.fill(a,0);
		Arrays.fill(b,0);
		Arrays.fill(c,0);
		Arrays.fill(d,0);
		 
		for(i = 0; i < n; ++i)
			for(j = 0; j < m; ++j)
				a[i][j] = Math.max(a[i][j-1], a[i-1][j]) + asal[i][j];
		 
		for(i = 0; i < n; ++i)
			for(j = 0; j < m; ++j)
				b[i][j] = Math.max(b[i-1][j], b[i][j+1]) + asal[i][j];
		 
		for(i = 0; i < n; ++i)
			for(j = 0; j < m; ++j)
				c[i][j] = Math.max(c[i+1][j], c[i][j-1]) + asal[i][j];
		 
		for(i = 0; i < n; ++i)
			for(j = 0; j < m; ++j)
				d[i][j] = Math.max(d[i][j+1], d[i+1][j]) + asal[i][j];
		 
		for(i = 0; i < n; ++i)
			for(j = 0; j < m; ++j) {
				long cur = 0 + a[i-1][j] + d[i+1][j] + b[i][j+1] + c[i][j-1];
				long cuh = 0 + a[i][j-1] + d[i][j+1] + b[i-1][j] + c[i+1][j];
				ans = Math.max(ans, Math.max(cur, cuh));
			}
		 
		out.println(ans);
		out.close();
		
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

}