// Cameron Showalter
// 2/17/2015
// calculates distance between two points. 
import java.util.*;
public class distance{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Distance Formula: \nX1: ");
        int xOne = in.nextInt();
        System.out.print("\nX2: ");
        int xTwo = in.nextInt();
        System.out.print("\nY1: ");
        int yOne = in.nextInt();
        System.out.print("\nY2: ");
        int yTwo = in.nextInt();
        System.out.print(" Distance: " +  distanceFormula(xTwo, xOne, yTwo, yOne));
        in.close();
    }
    //does the calculation with the inputed numbers
    public static double distanceFormula(double xTwo, double xOne, double yTwo, double yOne){
        return Math.sqrt(Math.pow((xTwo - xOne),2) + Math.pow((yTwo - yOne), 2));
    }
}