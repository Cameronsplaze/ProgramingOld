//  Cameron Showalter
//  3/4/2015
//  V1.0
//  Java 103
//  Homework 4.3
//  prints the range of numbers
import java.util.*;
    public class rangeWords{
        public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Your first value: ");
        int first = in.nextInt();
        System.out.print("Your second value: ");
        int second = in.nextInt();
        System.out.print(range(first, second));
        in.close();
    }
        //takes two values and prints everything inbetween them (including the values themselves)
    public static String range(int first, int second){
        String listOfChar = "";
        if(first <= second){
            for(int i=0; i < second - first + 1; i++){
                listOfChar = listOfChar + (i + first) + " ";
            }
            return listOfChar;
        }
        else{
            for(int i = 0; i<first - second + 1; i++){
                listOfChar = listOfChar + (first - i) + " ";
            }
            return listOfChar;
        }
    }
}