// Cameron Showalter
// 2/17/2015
// takes the abbsolute value of two numbers entered, then returns the bigger number.
import java.util.*;
public class theLargerAbsValue{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("First number: ");
        int firstValue = in.nextInt();
        System.out.print("\nSecond number: ");
        int secondValue = in.nextInt();
        System.out.print(largerAbsValue(firstValue, secondValue));
        in.close();
    }
    //takes the abbs of both numbers, and then shoves the bigger one into theBiggerOne and returnes it
    public static int largerAbsValue(int firstValue, int secondValue){
        int theBiggerOne = Math.max(Math.abs(firstValue), Math.abs(secondValue));
        return theBiggerOne;
    }
}