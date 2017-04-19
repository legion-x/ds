
/*Assignment No.13		Roll No. 47
Title : Java Program to demonstrate concept of interface and packages*/

--------------------------------------------------------------------------------------------------
ShapeArea.java
package Area;
import java.util.*;
public class ShapeArea
{
	public void circleArea()
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter radius of circle");
		int r=s.nextInt();
		System.out.println("Area of circle="+(3.14*r*r));
	}
	
	public void rectArea()
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter length of rectangle");
		int l=s.nextInt();
		System.out.println("Enter breadth of rectangle");
		int b=s.nextInt();
		System.out.println("Area of rectangle="+(l*b));
	}
	public void triangleArea()
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter base of triangle");
		int b=s.nextInt();
		System.out.println("Enter height of triangle");
		int h=s.nextInt();
		System.out.println("Area of rectangle="+(0.5*h*b));
	}
}

--------------------------------------------------------------------------------------------------
Volume.java

public interface Volume
{
	public void cylinder();
	public void cube();
	public void cone();
}

--------------------------------------------------------------------------------------------------
AreaVolume.java
import java.util.*;
import Area.ShapeArea;
class AreaVolume implements Volume
{
	public void cylinder()
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter radius of cylinder");
		int r=s.nextInt();
		System.out.println("Enter height of cylinder");
		int h=s.nextInt();
		System.out.println("volume of cylinder="+(3.14*h*r*r));
	}
	public void cube()
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter side of cube");
		int si=s.nextInt();
		System.out.println("volume of cube="+(si*si*si));
	}
	public void cone()
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter radius of cone");
		int r=s.nextInt();
		System.out.println("Enter height of cone");
		int h=s.nextInt();
		System.out.println("volume of cone="+(0.33*3.14*h*r*r));
	}
	public static void main(String args[])
	{
		AreaVolume av=new AreaVolume();
		Volume v;	//reference variable of interface volume
		ShapeArea a = new ShapeArea();	//reference variable of base class
		
		a.circleArea();
		a.rectArea();
		a.triangleArea();
		v=av;		//runtime polymorphism
		v.cylinder();
		v.cube();
		v.cone();
	}
}


/***************** ******  OUTPUT   **************************
Enter radius of circle
5
Area of circle=78.5
Enter length of rectangle
5
Enter breadth of rectangle
6
Area of rectangle=30
Enter base of triangle
10
Enter height of triangle
7
Area of rectangle=35.0
Enter radius of cylinder
5
Enter height of cylinder
10
volume of cylinder=785.0
Enter side of cube
3
volume of cube=27
Enter radius of cone
10
Enter height of cone
5
volume of cone=518.1

***********************************************************************/


