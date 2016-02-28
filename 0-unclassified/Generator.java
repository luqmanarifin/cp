import java.util.*;
import java.io.*;
import java.lang.*;

public class Generator {
  public Generator() {
    size = 0;
    rand = new Random();
    array = new ArrayList<Point>();
  }
  public Generator(int n) {
    size = n;
    rand = new Random();
    array = new ArrayList<Point>();
    for(int i = 0; i < size; i++) {
      int x = randInt(-1000, 1000);
      int y = randInt(-1000, 1000);
      int z = randInt(-1000, 1000);
      array.add(new Point(x, y, z));
    }
  }
  public ArrayList<Point> GetArray() {
    return array;
  }
  private int randInt(int min, int max) {
    int randomNum = rand.nextInt(max - min + 1) + min;
    return randomNum;
  }
  private ArrayList<Point> array;
  private int size;
  private Random rand;
}