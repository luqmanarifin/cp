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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	static final int MOD = (int) (1e9 + 7);
	
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		// type the code here
		int a = 0, b = 0;
		String aa = in.next();
		String bb = in.next();
		for(int i = 0; i < aa.length(); i += 2) {
			String aai = aa.substring(i, i+1);
			String aai1 = aa.substring(i+1, i+2);
			String bbi = bb.substring(i, i+1);
			String bbi1 = bb.substring(i+1, i+2);
			if(aai.equals("[") && bbi1.equals(")")) a++;
			else if(aai.equals("(") && bbi1.equals("<")) a++;
			else if(aai.equals("8") && bbi1.equals("]")) a++;
			else if(bbi.equals("[") && aai1.equals(")")) b++;
			else if(bbi.equals("(") && aai1.equals("<")) b++;
			else if(bbi.equals("8") && aai1.equals("]")) b++;
		}
		if(a > b)
			out.println("TEAM 1 WINS");
		else if(a < b)
			out.println("TEAM 2 WINS");
		else
			out.println("TIE");
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