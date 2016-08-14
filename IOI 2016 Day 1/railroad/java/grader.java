import java.io.*;
import java.util.StringTokenizer;

public class grader {
    public static void main(String[] args) {
        new grader().run();
    }

    private void run() {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        int n = nextInt();
        int[] s = new int[n], t = new int[n];
        for (int i = 0; i < n; ++i) {
            s[i] = nextInt();
            t[i] = nextInt();
        }
        long ans = new railroad().plan_roller_coaster(s, t);
        out.println(ans);
        out.close();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() {
        try {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    int nextInt() {
        return Integer.parseInt(next());
    }
}
