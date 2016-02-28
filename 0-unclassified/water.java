import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;

public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int w;
		Scanner cin = new Scanner(System.in);
		w = cin.nextInt();
		if(w % 2 == 0 && w != 2)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}