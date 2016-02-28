import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

public class Main {
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
		int n = in.nextInt();
		int x = in.nextInt();
		if(n == 5)
			out.println(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1");
		else if(n == 3)
			out.println(">vv\n^<.\n^.<\n1 3");
		else {
			for(int i = 0; i < 34; ++i) out.print(">");
			for(int i = 0; i < 32; ++i) out.print(".>");
			out.println("v.");
			
			out.print("^v");
			for(int i = 0; i < 32; ++i) out.print("<.");
			for(int i = 0; i < 33; ++i) out.print("<");
			out.println(".");
			
			for(int j = 0; j < 48; ++j) {
				out.print("^");
				for(int i = 0; i < 33; ++i) out.print(">");
				for(int i = 0; i < 32; ++i) out.print(".>");
				out.println("v.");
				
				out.print("^v");
				for(int i = 0; i < 32; ++i) out.print("<.");
				for(int i = 0; i < 33; ++i) out.print("<");
				out.println(".");
			}
			
			out.print("^");
			for(int i = 0; i < 33; ++i) out.print(">");
			for(int i = 0; i < 32; ++i) out.print(".>");
			out.println("v.");
			
			out.print("^.");
			for(int i = 0; i < 32; ++i) out.print("<.");
			for(int i = 0; i < 33; ++i) out.print("<");
			out.println(".");
			
			out.println("1 1");
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

}