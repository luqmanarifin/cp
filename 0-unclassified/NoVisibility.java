import java.util.*;

public class NoVisibility {  
    private static boolean ready;  
    private static int number;  
    private static class ReaderThread extends Thread {   
        public void run() {  
            while (!ready)   Thread.yield();  
            System.out.println(number);  
        }  
    } 
    public static void cok(int a) {
      System.out.println(a);
    }
    
    public static void main(String[] args) {  
        new ReaderThread().start(); 
        number = 5;
        ready = true;
        cok(new Integer(69));
        cok(new Integer(23));
    }  
}