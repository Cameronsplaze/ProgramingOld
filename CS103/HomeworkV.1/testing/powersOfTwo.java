import java.util.*;
public class powersOfTwo
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("What do you want to raise Two by?:");
        double number = in.nextDouble();
        System.out.print(number + "\n");
        powerNumber(number);
        in.close();
    }
    public static void powerNumber(double number)
    {
        System.out.println("banana");
        for(double i=0; i<number; i++)
        {
            System.out.print("Im here");
            System.out.print(Math.pow(2.0, i));
            
        }
    }
}