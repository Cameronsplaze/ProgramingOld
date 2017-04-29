//Cameron Showalter
//3-24-2015
//This program takes in numbers until a negative number is entered then tells you the average number of all them
import java.util.*;
public class average{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("This program takes the values of numbers and tells you the average");
        System.out.println("If the first number is negative the program ends.");
        System.out.print("\nType a number: ");
        
        double value = in.nextInt();
        double countTest = 1; //two because of the first and last value 
        double total = value;
        boolean done = false;
        while(done == false){
            if(value < 0){
                System.out.print(theAverage(total, countTest));
                done = true;
            }
            else{
                System.out.print("\nType a number: ");
                value = in.nextInt();
                total = total + value;
                countTest++;                
            }
        }
        in.close();
    }
    public static double theAverage(double total, double countTest){
        System.out.println(countTest);
        System.out.println(total);
        double average = total/countTest;
        return average;
    }
}