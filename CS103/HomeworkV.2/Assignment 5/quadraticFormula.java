// Cameron Showalter
// 2/17/2015
// Solves the Quadratic formula for you
import java.util.*;
public class quadraticFormula{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("Ax^2 + Bx + C");
        System.out.print("A: ");
        int a = in.nextInt();
        System.out.print("\nB: ");
        int b = in.nextInt();
        System.out.print("\nC: ");
        int c = in.nextInt();
        System.out.println(a + "x^2 + " + b + "x + " + c + ": ");
        runQuadratic(a, b, c);
        in.close();
        
    }
    //solves the quadratic formula. 
    public static void runQuadratic(double a, double b, double c){
        double positiveX = (-b + Math.sqrt(Math.pow(b, 2.0) - 4.0 * a * c))/ 2.0 * a;
        double negativeX = (-b - Math.sqrt(Math.pow(b, 2.0) - 4.0 * a * c))/ 2.0 * a;
        System.out.println("X = " + positiveX);
        System.out.println("X = " + negativeX);
    }
}