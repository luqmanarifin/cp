import java.util.*;
import java.io.*;
import java.lang.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class jumps {
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
	
	int[] mark;
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		int n = in.nextInt();
		int l = in.nextInt();
		int x = in.nextInt();
		int y = in.nextInt();
		mark = new int[n];
		for(int i = 0; i < n; i++) mark[i] = in.nextInt();
		boolean adax = false;
		boolean aday = false;
		for(int i = 0; i < n; i++) {
			int lef = i;
			int rig = n - 1;
			int goal = mark[i] + x;
			while(lef < rig) {
				int mid = (lef + rig) >> 1;
				if(mark[mid] < goal) lef = mid + 1;
				else rig = mid;
			}
			if(mark[lef] == goal) adax = true;
			
			lef = i;
			rig = n - 1;
			goal = mark[i] + y;
			while(lef < rig) {
				int mid = (lef + rig) >> 1;
				if(mark[mid] < goal) lef = mid + 1;
				else rig = mid;
			}
			if(mark[lef] == goal) aday = true;
		}
		if(adax && aday) {
			out.println(0);
		} else if(adax && !aday) {
			out.println(1);
			out.println(y);
		} else if(!adax && aday) {
			out.println(1);
			out.println(x);
		} else {
			for(int i = 0; i < n; i++) {
				int lef = 0;
				int rig = n - 1;
				int goal = mark[i] + x + y;
				while(lef < rig) {
					int mid = (lef + rig) >> 1;
					if(mark[mid] < goal) lef = mid + 1;
					else rig = mid;
				}
				if(mark[lef] == goal) {
					out.println(1);
					out.println(mark[i] + x);
					return;
				}
				
				lef = 0;
				rig = n - 1;
				goal = mark[i] + x - y;
				while(lef < rig) {
					int mid = (lef + rig) >> 1;
					if(mark[mid] < goal) lef = mid + 1;
					else rig = mid;
				}
				if(mark[lef] == goal && mark[i] + x <= l) {
					out.println(1);
					out.println(mark[i] + x);
					return;
				}
				
				lef = 0;
				rig = n - 1;
				goal = mark[i] - x + y;
				while(lef < rig) {
					int mid = (lef + rig) >> 1;
					if(mark[mid] < goal) lef = mid + 1;
					else rig = mid;
				}
				if(mark[lef] == goal) {
					out.println(1);
					out.println(mark[i] + x);
					return;
				}
				
				lef = 0;
				rig = n - 1;
				goal = mark[i] + x - y;
				while(lef < rig) {
					int mid = (lef + rig) >> 1;
					if(mark[mid] < goal) lef = mid + 1;
					else rig = mid;
				}
				if(mark[lef] == goal && goal <= a[n-1]) {
					out.println(1);
					out.println(mark[i] + x);
					return;
				}
			}
			out.println(2);
			out.println(x + " " + y);
		}
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