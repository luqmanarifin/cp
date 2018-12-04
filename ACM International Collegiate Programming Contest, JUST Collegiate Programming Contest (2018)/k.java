import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class k {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    OutputStream out = System.out;
    Task solver = new Task();
    solver.solve(1, in, out);
  }
}

class Task {
  String getKey(String s) {
    int at = s.indexOf('=');
    return s.substring(0, at);
  }
  String getValue(String s) {
    Pattern p = Pattern.compile("\\{(.*?)\\}");
    Matcher m = p.matcher(s);

    while (m.find()) {
      return m.group(1);
    }

    return "";
  }
  String formatAuthor(String s) {
    String names[] = s.split(",");
    StringBuilder ret = new StringBuilder();
    for (int i = 0; i < names.length; i++) {
      if (i > 0) {
        ret.append(", ");
      }
      String name = names[i].trim();
      String sname[] = name.split(" ");
      ret.append(sname[0].charAt(0));
      ret.append(sname[0].charAt(1));
      ret.append(". ");
      ret.append(sname[1].charAt(0));
    }
    return ret.toString();
  }

  public void solve(int testNumber, Scanner in, OutputStream out) {
    int t = Integer.parseInt(in.nextLine());
    while (t-- > 0) {
      int n = Integer.parseInt(in.nextLine());
      while (n-- > 0) {
        in.nextLine();
        Map map = new HashMap();
        for (int i = 0; i < 8; i++) {
          String str = in.nextLine();
          String key = getKey(str);
          String value = getValue(str);
          map.put(key, value);
        }
        in.nextLine();

        System.out.printf("%s. %s. %s. %s;%s(%s):%s.\n",
          formatAuthor((String)map.get("author")),
          map.get("title"),
          map.get("journal"),
          map.get("year"),
          map.get("volume"),
          map.get("number"),
          map.get("pages")
        );
      }
    }
  }
}
