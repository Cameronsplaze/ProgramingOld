//  Cameron Showalter
//  3/4/2015
//  V1.0
//  Java 103
//  Homework 4.3
//  takes in a date and month and returns what season it is
import java.util.*;
public class seasons{
    public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    System.out.print("What month is it?: ");
    int month = in.nextInt();
    System.out.print("\nWhat is the date?: ");
    int day = in.nextInt();
    System.out.print(season(month, day));
    in.close();
    }
    //returns what the season is based on month/day
    public static String season(int month, int day){
        String w = "Winter";
        String sp = "Spring";
        String s = "Summer";
        String f = "Fall"; 
            
        if(month == 1 || month == 2){
            return w;
        }
        else if(month == 3){
            if(day <=15){
                return w;
            }
            else{
                return sp;
            }
        }
        else if(month == 4 || month == 5){
            return sp;
        }
        else if(month == 6){
            if(day <=15){
                return sp;
            }
            else{
                return s;
            }
        }
        else if(month == 7 || month == 8){
        return s;
        }
        else if(month == 9){
            if(day <=15){
                return s;
            }
            else{
                return f;
            }
        }
        else if(month == 10 || month == 11){
        return f;
        }
        else{
            if(day <=15){
                return f;
            }
            else{
                return w;
            }
        }
    }
}