//Cameron Showalter
//3-24-2015
//tells you the GCD. (Coundnt get it working)
import java.util.*;
public class LowestCommonDenominator{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("This program tells you the LCD");
        System.out.print("The first number: ");
        int firstNumber = in.nextInt();
        System.out.print("The second number");
        int secondNumber = in.nextInt();
        System.out.print(GCD(firstNumber, secondNumber));
        in.close();
    }
    public static int GCD(int firstNumber, int secondNumber){
        if(secondNumber == 0){
            return firstNumber;
        }
        else{
            System.out.println(firstNumber + " " + secondNumber);
            return GCD(secondNumber, firstNumber%secondNumber);
        }
    }
}