// Cameron Showalter
// 2/17/2015
// lists out the wonderful powers of Two
import java.util.*;
public class powersOfTwo{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("What do you want to raise Two by?:");
        double number = in.nextDouble();
        powerNumber(number);
        in.close();
    }
    //loops the power of two to print all the powers before it
    public static void powerNumber(double number){
        for(double i=0; i<=number; i++){
            System.out.print(Math.pow(2.0, i) + "\t");   
        }
    }
}