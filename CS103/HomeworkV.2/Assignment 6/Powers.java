//  Cameron Showalter
//  3/4/2015
//  V1.0
//  Java 103
//  Homework 4.3
//  prints how the Math.pow works basically
import java.util.*;
public class Powers{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("What is the base number?: ");
        int base = in.nextInt();
        System.out.print("\nWhat is it raised to?: ");
        int raised = in.nextInt();
        System.out.print(Power(base, raised));
        in.close();
    }
    //does the actuall calculation
    public static String Power(int base, int raised){
        String variable = "";
        for(int i=1; i<=raised; i++){
            variable = variable + base;
            if(i != raised){ //makes sure its not the last number
                variable = variable + " * ";
            }
        }
    variable = variable + " = " + (int) Math.pow(base, raised);
    return variable;
    }
}