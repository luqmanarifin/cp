/**
 * Created by Luqman A. Siswanto on 19/11/2015.
 */
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test {
  public static void main(String[] args) {
    String a = "yes, now, no, kentang,      nice";
    String[] ret = a.split(",\\s*");
    for(String it : ret) {
      System.out.println(it);
    }
  }
}
