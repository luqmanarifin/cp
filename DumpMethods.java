import java.io.*;
import java.lang.reflect.Method;
import java.lang.reflect.Type;
import java.lang.reflect.InvocationTargetException;

public class DumpMethods {
    public static void main(String[] args) {
         try {
            Class c = Class.forName("java.util.Stack");
            Method m[] = c.getDeclaredMethods();
            for (int i = 0; i < m.length; i++)
                System.out.println(m[i].toString());
         }
         catch (Throwable e) {
            System.err.println(e);
         }
    }
}
