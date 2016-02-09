import java.util.*;
import java.io.*;
import java.lang.*;

public class Point implements Cloneable, Comparable<Point> {
  public Point() {
    this.x = 0;
    this.y = 0;
    this.z = 0;
  }
  public Point(int _x, int _y, int _z) {
    this.x = _x;
    this.y = _y;
    this.z = _z;
  }
  public Point(Point point) {
    this.x = point.x;
    this.y = point.y;
    this.z = point.z;
  }
  public double Dist(Point p) {
    ClosestPair.count++;
    double temp = 0;
    temp += (this.x - p.x)*(this.x - p.x);
    temp += (this.y - p.y)*(this.y - p.y);
    temp += (this.z - p.z)*(this.z - p.z);
    return Math.sqrt(temp);
  }
  @Override
  public int compareTo(Point p) {
    return this.x - p.x;
  }
  public static Comparator<Point> CompareByX = new Comparator<Point>() { 
    public int compare(Point p1, Point p2) {
      if(p1.x != p2.x) {
        return p1.x - p2.x;
      }
      if(p1.y != p2.y) {
        return p1.y - p2.y;
      }
      return p1.z - p2.z;
    }
  };
  public static Comparator<Point> CompareByY = new Comparator<Point>() { 
    public int compare(Point p1, Point p2) {
      if(p1.y != p2.y) {
        return p1.y - p2.y;
      }
      if(p1.z != p2.z) {
        return p1.z - p2.z;
      }
      return p1.x - p2.x;
    }
  };
  public static Comparator<Point> CompareByZ = new Comparator<Point>() { 
    public int compare(Point p1, Point p2) {
      if(p1.z != p2.z) {
        return p1.z - p2.z;
      }
      if(p1.y != p2.y) {
        return p1.y - p2.y;
      }
      return p1.x - p2.x;
    }
  };
  public int x, y, z;
}