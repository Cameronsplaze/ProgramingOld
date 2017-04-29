//  Cameron Showalter
//  3/4/2015
//  V1.0
//  Java 103
//  Homework 4.3
//  Takes values for a triangle and tells you what type of triangle this is and if its possible.
import java.util.*;
public class triangleType{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("First side of your triangle: ");
        int a = in.nextInt();
        System.out.print("Second side of your triangle: ");
        int b = in.nextInt();
        System.out.print("Third side of your triangle: ");
        int c = in.nextInt();
        if(trueTriangle(a, b, c) == true){
            System.out.print("The triangle is " + triangleTypes(a, b, c));
        }
        else{
            System.out.print("The values entered do not make a triangle");
        }
        in.close();
    }
    //prints the type of triangle
    public static String triangleTypes(int a, int b, int c){
        int minTemp = Math.min(a, b);
        int min = Math.min(minTemp, c);
        int maxTemp = Math.max(a, b);
        int max = Math.max(maxTemp, c);
        if(min == max){
            return "equilateral";
        }
        else if(a == b){
            return "isosceles";
        }
        else if(a == c){
            return "isosceles";
        }
        else if(b == c){
            return "isoceles";
        }
        else{
            return "scalene";
        }
    }
    //checks to see if the triangle is possible
    public static boolean trueTriangle(int a, int b, int c){
        int minTemp = Math.min(a, b);
        int min = Math.min(minTemp, c);
        int maxTemp = Math.max(a, b);
        int max = Math.max(maxTemp, c);
        
        int mid = (a + b + c) - min - max;
        if(min + mid < max){
            return false;
        }
        else{
            return true;
        }
    }
}