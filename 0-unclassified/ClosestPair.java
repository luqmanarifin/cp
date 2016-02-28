import java.util.*;
import java.io.*;
import java.lang.*;

public class ClosestPair {
  public static void main(String[] args) {
    System.out.println("\n\n");
    System.out.println("Closest Pair Problem\n");
    Generator gen = new Generator(1000000);
    points = new ArrayList<Point>(gen.GetArray());
    long startTime, duration;
    /*
    System.out.println("\n");
    System.out.println("Solved by Brute Force");
    System.out.println("------------------------------");
    startTime = System.nanoTime();
    SolveByBruteForce();
    duration = System.nanoTime() - startTime;
    ShowMessage(duration);
    */
    System.out.println("\n");
    System.out.println("Solved by Divide and Conquer");
    System.out.println("------------------------------");
    startTime = System.nanoTime();
    SolveByDivideAndConquer();
    duration = System.nanoTime() - startTime;
    ShowMessage(duration);
  }
  private static void ShowMessage(long duration) {
    System.out.println("Jumlah titik n = " + points.size());
    System.out.println("Penghitungan rumus Euclidean dilakukan " + count + " kali");
    System.out.println("Waktu yang dibutuhkan " + (double) duration / 1000000 + " ms");
    System.out.println("Jarak terdekat = " + result);
    System.out.println("Point 1 : " + p1.x + " " + p1.y + " " + p1.z);
    System.out.println("Point 2 : " + p2.x + " " + p2.y + " " + p2.z);
  }
  
  public ClosestPair() {
    this.result = inf;
    p1 = new Point();
    p2 = new Point();
  }
  public ClosestPair(ArrayList<Point> temp) {
    this.result = inf;
    p1 = new Point();
    p2 = new Point();
    points = new ArrayList<Point>(temp);
  }
  /* This is Brute Force solution, n^2 complexity in total */
  private static void SolveByBruteForce() {
    result = inf;
    count = 0;
    int size = points.size();
    for(int i = 0; i < size; i++) {
      for(int j = i + 1; j < size; j++) {
        Point p = new Point(points.get(i));
        double temp = p.Dist(points.get(j));
        if(temp < result) {
          result = temp;
          p1 = new Point(points.get(i));
          p2 = new Point(points.get(j));
        }
      }
    }
  }
  /* This is Divide and Conquer solution, n log n log n complexity in total */
  private static void SolveByDivideAndConquer() {
    result = inf;
    count = 0;
    Collections.sort(points, Point.CompareByX);
    Solve(new ArrayList<Point>(points));
  }
  private static void Solve(ArrayList<Point> p) {
    if(p.size() < 2) {
      return;
    }
    int size = p.size();
    int mid = (size - 1) / 2;
    double d = p.get(mid).x;
    ArrayList<Point> left = new ArrayList<Point>();
    ArrayList<Point> right = new ArrayList<Point>();
    ArrayList<Point> pLeft = new ArrayList<Point>();
    ArrayList<Point> pRight = new ArrayList<Point>();
    for(int i = 0; i < size; i++) {
      if(Math.abs(p.get(i).x - d) < result) {
        if(i <= mid) {
          left.add(p.get(i));
        } else {
          right.add(p.get(i));
        }
      }
      if(i <= mid) {
        pLeft.add(p.get(i));
      } else {
        pRight.add(p.get(i));
      }
    }
    Solve(pLeft);
    Solve(pRight);
    // n log n operation here
    Collections.sort(left, Point.CompareByY);
    Collections.sort(right, Point.CompareByY);
    TreeSet<Point> set = new TreeSet<Point>(Point.CompareByZ);
    int l = 0, r = 0;
    for(int i = 0; i < left.size(); i++) {
      while(r < right.size() && right.get(r).y < left.get(i).y + result) {
        set.add(right.get(r));
        r++;
      }
      while(l < r && right.get(l).y <= left.get(i).y - result) {
        set.remove(right.get(l));
        l++;
      }
      int limit = (int) Math.floor(left.get(i).z - result);
      Point temp = set.higher(new Point(Integer.MAX_VALUE, Integer.MAX_VALUE, limit));
      while(temp != null && temp.z < left.get(i).z + result) {
        double cur = temp.Dist(left.get(i));
        if(cur < result) {
          result = cur;
          p1 = new Point(temp);
          p2 = new Point(left.get(i));
        }
        temp = set.higher(temp);
      }
    }
  }
  static final double inf = (double) 1e4;     // constant infinity
  public static int count;                    // how many Dist method is called
  private static ArrayList<Point> points;     // store the 3D points
  private static double result;               // distance result of the Closest Pair
  private static Point p1, p2;                // pair result of the Closest Pair
}