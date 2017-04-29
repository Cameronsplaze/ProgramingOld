//  Cameron Showalter
//  3/4/2015
//  V1.0
//  Java 103
//  Homework 4.3
//  Tells you what is the biggest even number you entered is and all those even numbers added together
import java.util.*;
public class evenSumMax{
    public static void main(String[] args){
        int temp = 0;
        int maxOfEvens = Integer.MIN_VALUE;
        int totalEvens = 0;
        
        Scanner in = new Scanner(System.in);
        System.out.print("How many integers do you want to enter?: ");
        int numberInts = in.nextInt();
        for(int i=1; i<=numberInts; i++){
            System.out.print("\nInteger " + i + ": ");
            temp = in.nextInt();
            if( temp%2==0){
                totalEvens = totalEvens + temp;
                maxOfEvens = evenMax(maxOfEvens, temp);
            }
        }
        System.out.println("\nAdded total of all even integers: " + totalEvens);
        System.out.println("Biggest of all evens entered: " + maxOfEvens);
        in.close();
    }
    public static int evenMax(int maxOfEvens, int temp){
        int bigger = Math.max(maxOfEvens, temp);
        return bigger;
    }
}