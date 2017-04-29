//Cameron Showalter
//3-24-2015
//tells you if numbers entered are consecutative. (I get an error with Math and i dont know how to fix it.)
import java.util.*;
public class consecutive{
    public static void main(String[] args){
        System.out.print(consectutive(5, 4, 6));
        System.out.print(consectutive(2, 4, 5));
        System.out.print(consectutive(8, 7, 6));
        System.out.print(consectutive(3, 7, 5));
    }
    public static boolean consectutive(int a, int b, int c){
        int smallest = Math.min(a, b, c);
        int largest = Math.max(a, b, c);
        int middle = (a + b + c)-smallest - largest;
        if(smallest + 1 == middle && middle +1 == largest){
            return true;
        }
        else{
            return false;
        }
    }
}