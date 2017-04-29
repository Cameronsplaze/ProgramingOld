//  Cameron Showalter
//  3/4/2015
//  V1.0
//  Java 103
//  Homework 4.3
//  prints how the Math.pow works basically
import java.util.*;
public class PowersDouble{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("What is the base number?: ");
        double base = in.nextDouble();
        System.out.print("\nWhat is it raised to?: ");
        Double raised = in.nextDouble();
        System.out.print(Power(base, raised));
        in.close();
    }
    //does the actuall calculation
    public static String Power(Double base, Double raised){
        String variable = "";
        for(int i=1; i<=raised; i++){
            variable = variable + base;
            if(i != raised){ //makes sure its not the last number
                variable = variable + " * ";
            }
        }
    variable = variable + " = " + Math.pow(base, raised);
    return variable;
    }
}