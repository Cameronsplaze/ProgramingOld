//  Cameron Showalter
//  3/4/2015
//  V1.0
//  Java 103
//  Homework 4.3
//  tells you the largest and smallest of numbers inputed
import java.util.*;
public class SmallerLarger{
    public static void main(String[] args){
        int small = Integer.MAX_VALUE;//looked up online, hope its ok.
        int large = Integer.MIN_VALUE;//this way they cant enter a number out of bounds
        int temp = 0;
        
        Scanner in = new Scanner(System.in);
        System.out.print("How many numbers would you like to print?");
        int numbersToPrint = in.nextInt();
        for(int i=1; i<=numbersToPrint; i++){
            System.out.print("\nNumber " + i + ": ");
            temp = in.nextInt();
            large = Largest(temp, large);
            small = Smallest(temp, small);         ;   
        }
        System.out.println("\nLargest number: " + large);
        System.out.println("Smallest number: " + small);
        in.close();
    }
    //returns the smallest of two numbers
    public static int Smallest(int temp, int smallest){
        int min = Math.min(temp, smallest);
        return min;
    }
    //returns the largest of two numbers
    public static int Largest(int temp, int largest){
        int max = Math.max(temp, largest);
        return max;
    }
}