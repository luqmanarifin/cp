import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

class Bapak {
  public Bapak() {
    x = 0;
  }
  public Bapak(int a) {
    x = a;
  }
  public void print() {
    System.out.println("Ini bapak " + x);
  }
  protected int x;
}

class Anak extends Bapak {
  public Anak() {
    this.x = 0;
  }
  public Anak(int a) {
    this.x = a;
  }
  public void print() {
    System.out.println("Ini anak " + x);
  }
}

class Box<T> {
  private T t;
  public void add(T t) {
    this.t = t;
  }
  public T get() {
    return t;
  }
  public<U> void inspect (U u) {
    System.out.println("T : " + t.getClass().getName());
    System.out.println("U : " + u.getClass().getName());
  }
  public static void main(String[] args) {
    Box<Integer> integerBox = new Box<Integer>();
    integerBox.add(new Integer(10));
    integerBox.inspect("some text");
  }
}
/*
class jajal {
  public static void f(Bapak b) {
    b.print();
  }
  public static void main(String[] args) {
    Anak a = new Anak(5);
    f(a);
  }
} */