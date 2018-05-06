import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

class RemoveHeader {
  public static void main(String[] args) throws Exception {
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

  public static void writeFile(File file, List<String> list) throws Exception {
    FileWriter writer = new FileWriter(file.getAbsolutePath());
    for (String s : list) {
      writer.write(s + "\n");
    }
    writer.close();
  }

  public static void removeHeader(File file) throws Exception {
    Scanner input = new Scanner(file);
    List<String> list = new ArrayList<String>();

    while (input.hasNextLine()) {
        list.add(input.nextLine());
    }

    for (int i = 0; i < list.size(); i++) {
      String s = list.get(i).trim();
      if (s.equals("")) {

      } else if (s.equals("/*")) {
        for (int j = i + 1; j < list.size(); j++) {
          String sj = list.get(j).trim();
          if (sj.equals("*/")) {
            List<String> lol = new ArrayList<String>();
            for (int k = j + 1; k < list.size(); k++) {
              lol.add(list.get(k));
            }
            writeFile(file, lol);
            break;
          }
        }
        break;
      } else {
        break;
      }
    }
  }

  public static void showFiles(File[] files) throws Exception {
    for (File file : files) {
      if (file.isDirectory()) {
        System.out.println("Directory: " + file.getName());
        showFiles(file.listFiles()); // Calls same method again.
      } else {
        System.out.println("File: " + file.getName());
        if (file.getName().endsWith(".cpp")) {
          removeHeader(file);
        }
      }
    }
  }

  public void solve(int testNumber, InputReader in, PrintWriter out) throws Exception {
    out.println("hello world");
    File[] files = new File("/home/luqman/Code/cp").listFiles();
    showFiles(files);
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
